add_executable(hello1 hello1.cpp)
target_link_libraries(hello1 pthread)

add_executable(hello2 hello2.cpp)
target_link_libraries(hello2 pthread)

add_executable(hello3 hello3.cpp)
target_link_libraries(hello3 pthread)

add_executable(hello4 hello4.cpp)
target_link_libraries(hello4 pthread)

add_executable(counter counter.cpp)
target_link_libraries(counter pthread)

add_executable(mutex1 mutex1.cpp)
target_link_libraries(mutex1 pthread)

add_executable(mutex2 mutex2.cpp)
target_link_libraries(mutex2 pthread)

add_executable(mutex3 mutex3.cpp)
target_link_libraries(mutex3 pthread)

add_executable(mutex4 mutex4.cpp)
target_link_libraries(mutex4 pthread)


add_executable(cv1 cv1.cpp)
target_link_libraries(cv1 pthread)

add_executable(cv2 cv2.cpp)
target_link_libraries(cv2 pthread)

add_executable(cv3_timed cv3_timed.cpp)
target_link_libraries(cv3_timed pthread)

add_executable(bounded_buffer bounded_buffer.cpp)
target_link_libraries(bounded_buffer pthread)

if(WIN32)
    # Disable warning on boost string algorithms.
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    add_executable(semaphore_win32 semaphore_win32.cpp)
endif()

add_executable(semaphore semaphore.cpp)
target_link_libraries(semaphore pthread)

add_executable(rwlock1 rwlock1.cpp)
target_link_libraries(rwlock1 pthread)

# upgrade_lock is Boost only.
# add_executable(rwlock2_upgrade rwlock2_upgrade.cpp)
