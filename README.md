# zed-docker

The repository contains a GitHub Actions workflow for auto-deployment of built Docker image to https://hub.docker.com/r/husarion/zed_desktop & https://hub.docker.com/r/husarion/zed_jetson repository.

## Docker image usage

Available repos: 
- **`zed-desktop:noetic`** for desktop platform with CUDA (tested on platform with 11.7).
- **`zed-jetson:noetic`** for Jetson platform currently support - **Jetson Xavier, Orin AGX/NX/Nano, CUDA 11.4** (tested on Xavier AGX).
- **`zed-jetson:melodic`** for Jetson platform currently not supported - **Jetson Nano, TX2/TX2 NX, CUDA 10.2** (tested on Nano).

## Development

### Get image
**a) Building a Docker image**

```bash
docker build -t zed -f Dockerfile.<select_image> .
```
**b) Pulling the Docker image**

```bash
docker pull husarion/zed-<select_image>
```

### Running a Docker image

**a) Running on desktop**

```bash
docker run --gpus all -it --privileged --rm zed roslaunch zed_wrapper <camera_model>.launch
```

**b) Running on desktop**

```bash
docker run --runtime=nvidia -it --privileged --rm zed roslaunch zed_wrapper <camera_model>.launch
```

## Docker Compose

Connect ZED camera to your platform, open compose depending on the platform you are working on and in the `<camera model>` field, **enter the model name of the connected camera**. Then run:

```bash
cd demo
export DISPLAY=:1
xhost local:root
docker compose -f compose.<select_platform>.yaml up
```
