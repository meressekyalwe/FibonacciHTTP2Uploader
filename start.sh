#!/bin/bash
PROJECT_NAME=fibonacci_http2_uploader
docker build -t ${PROJECT_NAME} .
docker run --rm -it --name ${PROJECT_NAME} ${PROJECT_NAME}
