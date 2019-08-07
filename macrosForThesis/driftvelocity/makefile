GARFIELD_HOME = /home/justin/garfield/

OBJDIR = $(GARFIELD_HOME)/Object
SRCDIR = $(GARFIELD_HOME)/Source
INCDIR = $(GARFIELD_HOME)/Include
HEEDDIR = $(GARFIELD_HOME)/Heed
LIBDIR = $(GARFIELD_HOME)/Library

# Compiler flags
CXX = `root-config --cxx`
CFLAGS = `root-config --cflags` \
	-O3 -W -Wall -Wextra -Wno-long-long \
	-fno-common \
	-I$(INCDIR) -I$(HEEDDIR)

# Debug flags
# CFLAGS += -g
OBJS = getDriftVel.o
LDFLAGS = -L$(LIBDIR) -lGarfield
LDFLAGS += `root-config --glibs` -lGeom -lgfortran -lm

all: drift

drift: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o drift $(LDFLAGS)

getDriftVel.o: getDriftVel.C
	$(CXX) $(CFLAGS) -c getDriftVel.C $(LDFLAGS)
clean:
	rm getDriftVel.o drift
