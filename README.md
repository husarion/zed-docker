<h1 align="center">
  Docker Images for ZED Camera
</h1>

The repository contains a GitHub Actions workflow for auto-deployment of built Docker images to [husarion/zed_desktop](https://hub.docker.com/r/husarion/zed-desktop), [husarion/zed_desktop-cpu](https://hub.docker.com/r/husarion/zed-desktop-cpu) and [husarion/zed_jetson](https://hub.docker.com/r/husarion/zed-jetson) Docker Hub repositories.

[![ROS Docker Image](https://github.com/husarion/zed-docker/actions/workflows/ros-docker-image.yaml/badge.svg)](https://github.com/husarion/zed-docker/actions/workflows//ros-docker-image.yaml)


## Available repos

**ROS1:**
- **`husarion/zed-desktop:noetic`** for desktop platform with CUDA (tested on platform with 11.7).
- **`husarion/zed-desktop-cpu:noetic`** a simple demo version on the CPU, allowing you to check if the camera and IMU are working properly. Image dedicated to platforms with amd64 and arm64 architecture.
- **`husarion/zed-jetson:noetic`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).
- **`husarion/zed-jetson:melodic`** for Jetson platform currently not supported - **Jetson Nano, TX2/TX2 NX, CUDA 10.2** (tested on Nano).

**ROS2:**
- **`husarion/zed-desktop:humble`** for desktop platform with CUDA (tested on platform with 11.7).
- **`husarion/zed-desktop-cpu:humble`** a simple demo version on the CPU, allowing you to check if the camera and IMU are working properly. Image dedicated to platforms with amd64 and arm64 architecture.
- **`husarion/zed-jetson:foxy`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).

## Prepare environment

1. Simply plugin the camera into **USB 3.0** port. Then use `lsusb` command to check if the device is visible.

2. Before you started it is recommended to select appropriate image and indicate the camera model.

```bash
export ZED_IMAGE=<zed_image>
export CAMERA_MODEL=<camera_model>
```

> [!NOTE]
> To run ZED X camera with Jetson Orin Nano install the ZED X Driver. Follow the official tutorial [Setting up ZED X on Orin Nano / NX Developer Kits](https://www.stereolabs.com/docs/get-started-with-zed-x/jetson-orin-devkit-setup/) from Stereolabs.

## Demo

1. Clone repository.

```bash
git clone https://github.com/husarion/zed-docker.git
```

2. Pulling the Docker images.

```bash
cd zed-docker/demo
docker compose pull
```

3. Run compose.

```bash
xhost local:root
docker compose up
```

> **INFO:**
>
> First run of **ROS 2** Docker images downloads configuration files and camera optimization. This may take several minutes. Therefore, remember to mount the volume inside the container.

4. Configure RViz.

- RGB image topic: `/<camera_model>/zed_node/rgb/image_rect_color`
- Point cloud topic: `/<camera_model>/zed_node/point_cloud/cloud_registered`

## Additional details

Docker Compose volume `- /tmp/argus_socket:/tmp/argus_socket` is only necessary for ZED X camera.

## Known issue

Docker Buildkit doesn't support build image with Nvidia runtime, so there is dedicated action for pushing locally building image from Jetson.
