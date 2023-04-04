a demo of observer / pub-sub pattern

# how to run?

`make` (if `make` command is installed on your machine.)

# then what you will see?

three observers (subscribers) receive various notifications.

# situation

- Many publishers want to send events to their subscribers. 
- Subscribers want to subscribe various publishers
- they do not need mutual communication. a publisher always sends messages and a subscriber always receives messages. 

# how to read these codes?

1. first, read `main.cpp` and see the program's overview.
2. second, read  `publisher.h` and `observer.h`.
    - They are just interfaces and have no corresponding implementation.
    - They exist just to clarify what multiple kinds of observers shoud be able to and what multiple kinds of publishers should be able to.
        - (In this program, just only one kind of observers and one kind of publishers are implemented. But usually, the program will have many kinds of those.)
3. finally, read anything else.


# others

- I ran this program locally on WSL and worked expectedly.
