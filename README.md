# zed-docker

The repository contains a GitHub Actions workflow for auto-deployment of built Docker images to [husarion/zed_desktop](https://hub.docker.com/r/husarion/zed-desktop) and [husarion/zed_jetson](https://hub.docker.com/r/husarion/zed-jetson) Docker Hub repositories.

## Docker image usage

Available repos

**ROS1:**
- **`zed-desktop:noetic`** for desktop platform with CUDA (tested on platform with 11.7).
- **`zed-jetson:noetic`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).
- **`husarion/zed-jetson:melodic`** for Jetson platform currently not supported - **Jetson Nano, TX2/TX2 NX, CUDA 10.2** (tested on Nano).

**ROS2:**
- **`husarion/zed-desktop:humble`** for desktop platform with CUDA (tested on platform with 11.7).
- **`husarion/zed-jetson:foxy`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).

> **INFO:**
>
> First running of **ROS 2** Docker images, download configuration files and optimize camera. It may take few minuts. That's why you should remember about mounting a volumen inside the container.

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
docker run --runtime nvidia -it --privileged -v /dev/shm:/dev/shm  \
  ${ZED_IMAGE} \
  roslaunch zed_wrapper ${CAMERA_MODEL}.launch
```

## Running demo with Docker compose

Connect ZED camera to your platform, `export CAMERA_MODEL` and run following commands:

```bash
cd demo
export DISPLAY=:1
xhost local:root
docker compose up
```

## Issue

Docker Buildkit doesn't support build image with Nvidia runtime, so there is dedicated action for pushing locally building image from Jetson.  