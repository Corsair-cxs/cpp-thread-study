#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

// See also:
// http://progsch.net/wordpress/?p=71
// http://stackoverflow.com/questions/17156541/why-do-we-need-to-use-boostasioio-servicework

class ThreadPool {
public:
  explicit ThreadPool(size_t size) : work_(io_service_) {
    for (size_t i = 0; i < size; ++i) {
      workers_.create_thread(boost::bind(&boost::asio::io_service::run, &io_service_));
    }
  }

  ~ThreadPool() {
    io_service_.stop();
    workers_.join_all();
  }

  // Add new work item to the pool.
  template<class F>
  void Enqueue(F f) {
    io_service_.post(f);
  }

private:
  boost::thread_group workers_;
  boost::asio::io_service io_service_;

  // Why need io_service::work? See:
  //   http://stackoverflow.com/questions/13219296/why-should-i-use-io-servicework
  boost::asio::io_service::work work_;
};

int main() {
  // Create a thread pool of 4 worker threads.
  ThreadPool pool(4);

  // Queue a bunch of work items.
  for (int i = 0; i < 8; ++i) {
    pool.Enqueue([i] {
      std::cout << "hello " << i << std::endl;
      boost::this_thread::sleep(boost::posix_time::seconds(1));
      std::cout << "world " << i << std::endl;
    });
  }

  return 0;
}
