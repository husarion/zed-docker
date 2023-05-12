# zed-docker

The repository contains a GitHub Actions workflow for auto-deployment of built Docker images to [husarion/zed_desktop](https://hub.docker.com/r/husarion/zed-desktop) and [husarion/zed_jetson](https://hub.docker.com/r/husarion/zed-jetson) Docker Hub repositories.

## Docker image usage

Available repos: 
- **`husarion/zed-desktop:noetic`** for desktop platform with CUDA (tested on platform with 11.7).
- **`husarion/zed-jetson:noetic`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).
- **`husarion/zed-jetson:melodic`** for Jetson platform currently not supported - **Jetson Nano, TX2/TX2 NX, CUDA 10.2** (tested on Nano).

## Prepare environment

Before you started it is recommanded to setup few variables.

```bash
export ZED_IMAGE=<zed_image>
export CAMERA_MODEL=<camera_model>
```

## Development

### Get image
**a) Building a Docker image**

```bash
docker build -t <image_tag> -f <select_dockerfile> .
```
**b) Pulling the Docker image**

```bash
docker pull ${ZED_IMAGE}
```

### Running a Docker image

**Running on desktop**

```bash
docker run --runtime nvidia -it --privileged --ipc=host --pid=host -e DISPLAY \
  -v /dev/shm:/dev/shm -v /tmp/.X11-unix/:/tmp/.X11-unix \
  -v /tmp/zed_ai/:/usr/local/zed/resources/ \
  ${ZED_IMAGE} \
  roslaunch zed_wrapper ${CAMERA_MODEL}.launch
```

## Docker Compose

Connect ZED camera to your platform, open compose depending on the platform you are working on and in the `<camera model>` field, **enter the model name of the connected camera**. Then run:

```bash
cd demo
export DISPLAY=:1
xhost local:root
docker compose -f compose.<select_platform>.yaml up
```
