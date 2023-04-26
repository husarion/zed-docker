# zed-docker

[![Build/Publish Docker Image](https://github.com/husarion/astra-docker/actions/workflows/build-docker-image.yaml/badge.svg)](https://github.com/husarion/astra-docker/actions/workflows/build-docker-image.yaml)

Dockerized Orbbec ROS 2 Astra package: `OpenNI_SDK_ROS2_v1.0.2` built for ROS 2 Humble, Galactic and Foxy distros.

The repository contains a GitHub Actions workflow for auto-deployment of built Docker image to https://hub.docker.com/r/husarion/astra repository.

## Docker image usage

Available tags: `amd64`, `aarch64`.

### Pulling the Docker image

```bash
docker pull husarion/zed:amd64
```

### Running a Docker image

```bash
sudo docker run --rm -it \
--device /dev/bus/usb/ \
husarion/zed:amd64 \
roslaunch zed_wrapper zed2.launch # select launch according to your camera model
```

## Development

### Building a Docker image

```bash
sudo docker build -t zed .
```

### Running a Docker image

```bash
sudo docker run --rm -it \
--device /dev/bus/usb/ \
astra \
roslaunch zed_wrapper zed2.launch # select launch according to your camera model
```

## Examples (using Docker Compose)

### Astra container + RViz2 container

Connect Orbbec Astra camera to your laptop and run:

```bash
cd demo

xhost local:root
docker-compose up --build
```
