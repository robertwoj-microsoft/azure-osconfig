## Filesystem fuzzer
This directory contains a POC implementation of filesystem fuzzer which generates files based on input and excercises the ASB library.
### Bulid
From the root of the repository, go to:
```
cd src/experimental/fs-fuzzer
```
Then, build a container which will run the fuzzer:
```
docker build . -t fuzzer-ubuntu
```
Now, build the sources:
```
docker run --rm -it -v /home/robert/work/azure-osconfig:/sources -v fuzzer-build:/build fuzzer-ubuntu /bin/bash /app/build.bash
```
### Run
Run the fuzzer with the following command:
```
mkdir /tmp/corpus
cp 43119747-263c-2c92-4ce5-726e63259049-fstab /tmp/corpus
docker run --privileged --rm -it -v fuzzer-build:/build -v /tmp/corpus/:/corpus fuzzer-ubuntu /bin/bash /app/run.bash
```
*Note*: The --privileged flag is required for the fuzzer to remount root filesystem frequently.