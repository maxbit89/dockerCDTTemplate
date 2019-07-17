DOCKER_USERNAME = maxbit89

DOCKER_DEBIAN_BUILD_IMAGE_BUILD_LOCAL   = DEFINED #ifnot it will be pulled from Docker Hub or other configured Docker Registry.
DOCKER_DEBIAN_BUILD_IMAGE_BUILD_DO_PUSH = DEFINED #if DOCKER_DEBIAN_BUILD_IMAGE_BUILD_LOCAL is enabled,
                                                  #the image will be pushed to Docker Hub or other configured Docker Registry.
DOCKER_DEBIAN_BUILD_IMAGENAME           = $(DOCKER_USERNAME)/debian-buildessential1.0
DOCKER_DEBIAN_BUILD_IMAGE               = debian-buildessential.tar
DOCKER_DEBIAN_BUILD_DOCKERFILE          = dockerfile

all:$(DOCKER_DEBIAN_BUILD_IMAGE)

$(DOCKER_DEBIAN_BUILD_IMAGE):$(DOCKER_DEBIAN_BUILD_DOCKERFILE)
	@echo "Build Step: $(DOCKER_DEBIAN_BUILD_IMAGE)"
ifdef DOCKER_DEBIAN_BUILD_IMAGE_BUILD_LOCAL
	@echo "Mode: Local"
	docker build -t $(DOCKER_DEBIAN_BUILD_IMAGENAME) -f $(DOCKER_DEBIAN_BUILD_DOCKERFILE) .
ifdef DOCKER_DEBIAN_BUILD_IMAGE_BUILD_DO_PUSH
		docker push $(DOCKER_DEBIAN_BUILD_IMAGENAME)
endif
else
	@echo "Mode: Pull"
	docker pull $(DOCKER_DEBIAN_BUILD_IMAGENAME)
endif
	docker save --output $(DOCKER_DEBIAN_BUILD_IMAGE) $(DOCKER_DEBIAN_BUILD_IMAGENAME)
	
clean:
	-rm $(DOCKER_DEBIAN_BUILD_IMAGE)
	
mrpropper: clean
	-docker system prune -a