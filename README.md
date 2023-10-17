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

**1. Plugin the camera**

For best performance please use **USB 3.0** port, depend of the camera model. Then use `lsusb` command to check if the device is visible.

## Demo

**1. Clone repository.**

```bash
git clone https://github.com/husarion/zed-docker.git
cd zed-docker/demo
```

**2. Select your appropriate Docker image**

```bash
export ZED_IMAGE=<zed_image>
```

**3. Select the appropriate launch file**

```bash
export CAMERA_LAUNCH=<camera_launch>
```

Replace `<camera_launch>` with appropriate launch file for your camera from below table.

<div class="center-table">

| **Product name**  | **Launch file**         |
| ----------------- | ----------------------- |
| ZED               | zed.launch.py           |
| ZED Mini          | zedm.launch.py          |
| ZED 2             | zed2.launch.py          |
| ZED 2i            | zed2i.launch.py         |
| ZED X             | zedx.launch.py          |
| ZED X Mini        | zedxm.launch.py         |

> [!IMPORTANT]
> To use the ZED X camera, you'll need to install the ZED X Driver additionally. Follow the official tutorial [Setting up ZED X on Orin Nano / NX Developer Kits](https://www.stereolabs.com/docs/get-started-with-zed-x/jetson-orin-devkit-setup/) provided by Stereolabs for detailed instructions.


**4. Run `compose.yaml`**

```bash
xhost local:root
docker compose up
```

> [!NOTE]
> First run of **ROS 2** Docker images downloads configuration files and optimize camera. This may take several minutes.

**5. Configure RViz.**

Add following topic to RViz:
- RGB image topic: `/<camera_model>/zed_node/rgb/image_rect_color`
- Point cloud topic: `/<camera_model>/zed_node/point_cloud/cloud_registered`

## Additional details

Docker Compose volume `- /tmp/argus_socket:/tmp/argus_socket` is only necessary for ZED X camera.

## Known issue

Docker Buildkit doesn't support build image with Nvidia runtime, so there is dedicated action for pushing locally building image from Jetson.
