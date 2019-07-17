DOCKER_USERNAME = maxbit89

DOCKER_ALPINE_BUILD_IMAGE_BUILD_LOCAL   = DEFINED #ifnot it will be pulled from Docker Hub or other configured Docker Registry.
DOCKER_ALPINE_BUILD_IMAGE_BUILD_DO_PUSH = DEFINED #if DOCKER_ALPINE_BUILD_IMAGE_BUILD_LOCAL is enabled,
                                                  #the image will be pushed to Docker Hub or other configured Docker Registry.
DOCKER_ALPINE_BUILD_IMAGENAME           = $(DOCKER_USERNAME)/alpine-buildessential1.0
DOCKER_ALPINE_BUILD_IMAGE               = alpine-buildessential.tar
DOCKER_ALPINE_BUILD_DOCKERFILE          = dockerfile

all:$(DOCKER_ALPINE_BUILD_IMAGE)

$(DOCKER_ALPINE_BUILD_IMAGE):$(DOCKER_ALPINE_BUILD_DOCKERFILE)
	@echo "Build Step: $(DOCKER_ALPINE_BUILD_IMAGE)"
ifdef DOCKER_ALPINE_BUILD_IMAGE_BUILD_LOCAL
	@echo "Mode: Local"
	docker build -t $(DOCKER_ALPINE_BUILD_IMAGENAME) -f $(DOCKER_ALPINE_BUILD_DOCKERFILE) .
ifdef DOCKER_ALPINE_BUILD_IMAGE_BUILD_DO_PUSH
		docker push $(DOCKER_ALPINE_BUILD_IMAGENAME)
endif
else
	@echo "Mode: Pull"
	docker pull $(DOCKER_ALPINE_BUILD_IMAGENAME)
endif
	docker save --output $(DOCKER_ALPINE_BUILD_IMAGE) $(DOCKER_ALPINE_BUILD_IMAGENAME)
	
clean:
	-rm $(DOCKER_ALPINE_BUILD_IMAGE)
	
mrpropper: clean
	-docker system prune -a