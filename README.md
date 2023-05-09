# zed-docker

The repository contains a GitHub Actions workflow for auto-deployment of built Docker image to https://hub.docker.com/r/husarion/zed repository.

## Docker image usage

Available repos: 
- `zed-desktop` for desktop platform with CUDA.
- `zed-jetson` for Jetson platform.

**Pulling the Docker image**

```bash
docker pull husarion/zed-desktop:noetic
```

**Running a Docker image**

```bash
docker run --gpus all -it --privileged --rm husarion/zed_desktop:noetic roslaunch zed_wrapper <camera_model>.launch
```

## Development

**Building a Docker image**

```bash
docker build -t zed -f Dockerfile.<select_image> .
```
**Running a Docker image**

```bash
docker run --gpus all -it --privileged --rm zed roslaunch zed_wrapper <camera_model>.launch
```

## Examples (using Docker Compose)

Connect ZED camera to your platform, open compose depending on the platform you are working on and in the field `<camera model>` enter the model name of the connected camera. Then run:

```bash
cd demo
export DISPLAY=:1
xhost local:root
docker compose -f compose.<select_platform>.yaml up
```
