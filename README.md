# Zephyr and gtest example

Here is a tiny Zephyr application with a simple unit test using the gtest (GoogleTest) harness.

## Getting started
(Assuming you have a working Zephyr development environment already)

I'm using a west.yml file to setup the application in a west workspace. No need to `git clone` the repo
like you are used to. `west init` can handle that for you. See below. 

### Initialization

The first step is to initialize the workspace folder (`zephyr-gtest-workspace`) where
the `zephyr-gtest-example` and all Zephyr modules will be cloned. Run the following
command:

```shell
# initialize zephyr-gtest-workspace for the zephyr-gtest-example (main branch)
west init -m https://github.com/carljohanlandin/zephyr-gtest-example --mr main zephyr-gtest-workspace
# update zephyr modules
cd zephyr-gtest-workspace
west update
```

### Building and running

To build the application (and the unit tests), run the following command:

```shell
cd zephyr-gtest-example
west build -b native_posix .
```
To run the tests in the generated `hello_test` binary:
```shell
cd build
./hello_test
```

or

```shell
cd build
ctest
```

### Twister
Unfortunately I haven't figured out how to make use of `twister` yet. I know there is support for `gtest` within twister though. If you know how to do it, please hit me with a pull request :)

## Contributions
If you have thoughts or ideas on how to improve my configuration to use gtest with zephyr, please let me know. With a message or a PR .
