DOCKER_USERNAME = maxbit89

#Build Image Dependencies:
DOCKER_BUILD_TARGET = debian
DOCKER_BUILD_IMAGEPATH = ../docker-$(DOCKER_BUILD_TARGET)-build-img
DOCKER_BULD_IMAGE      = $(DOCKER_BUILD_IMAGEPATH)/$(DOCKER_BUILD_TARGET)-buildessential.tar
DOCKER_BUILD_IMAGENAME = maxbit89/$(DOCKER_BUILD_TARGET)-buildessential1.0
$(DOCKER_BULD_IMAGE):
	cd $(DOCKER_BUILD_IMAGEPATH) && make clean && make

#Build Application Dependencies:
APPLICATION_DIRECTORY = ../src
APPLICATION_NAME      = HelloWorld
APPLICATION           = $(APPLICATION_DIRECTORY)/$(APPLICATION_NAME)
	
#Application Image Build:
#DOCKER_APPLICATION_IMAGE_BUILD_DO_PUSH = DEFINED #if DOCKER_ALPINE_BUILD_IMAGE_BUILD_LOCAL is enabled,
                                                 #the image will be pushed to Docker Hub or other configured Docker Registry.
DOCKER_APPLICATION_IMAGENAME           = $(DOCKER_USERNAME)/example-helloworld1.0
DOCKER_APPLICATION_IMAGE               = HelloWorld.tar
DOCKER_APPLICATION_DOCKERFILE          = dockerfile
	
all:$(DOCKER_APPLICATION_IMAGE)

$(DOCKER_APPLICATION_IMAGE):$(DOCKER_APPLICATION_DOCKERFILE) $(APPLICATION)
	cp $(APPLICATION) ./$(APPLICATION_NAME)
	docker build --build-arg TARGET=$(DOCKER_BUILD_TARGET) --build-arg APPLICATION=./$(APPLICATION_NAME) -t $(DOCKER_APPLICATION_IMAGENAME) -f $(DOCKER_APPLICATION_DOCKERFILE) .
ifdef DOCKER_APPLICATION_IMAGE_BUILD_DO_PUSH
	docker push $(DOCKER_APPLICATION_IMAGENAME)
endif
	docker save --output $(DOCKER_APPLICATION_IMAGE) $(DOCKER_APPLICATION_IMAGENAME)

mrpropper: clean
	-docker system prune -a

clean: app-clean
	-rm $(DOCKER_APPLICATION_IMAGE)

app-clean:
	cd $(APPLICATION_DIRECTORY) && make clean
	
$(DOCKER_APPLICATION):
	@echo "Build Step: $(DOCKER_APPLICATION)"
	docker run -ti -v $$(pwd)/src:/build $(DOCKER_BUILD_IMAGENAME) "/bin/sh" -c "make clean && make"