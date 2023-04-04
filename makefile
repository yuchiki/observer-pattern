.PHONY: run_sample
run_sample: sample
	./sample

sample: user.cpp timer_publisher.cpp main.cpp
	g++ -pthread -o sample user.cpp timer_publisher.cpp main.cpp
