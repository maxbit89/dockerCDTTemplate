PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ARTIFACT_NAME = HelloWorld

OBJS = HelloWorld.o

CFLAGS += -g

all:	HelloWorld

$(ARTIFACT_NAME):$(ARTIFACT_NAME)Debug
	cp $< $@
	strip -g $@

$(ARTIFACT_NAME)Debug:$(OBJS)
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr HelloWorld HelloWorldDebug $(OBJS)