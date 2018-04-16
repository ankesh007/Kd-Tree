ifndef VERBOSE
.SILENT:
endif
# .SILENT:clean
# .SILENT:KdTree
HEADER_DIR=.
OBJDIR=obj
LIBS=-std=c++14
# SRCS=KdTree.cpp main.cpp query.cpp 
SRCS=KdTree.cpp mainseq.cpp query.cpp 

DEPS = $(wildcard $(HEADER_DIR)/*.h)
OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))

$(OBJDIR)/%.o: %.cpp $(DEPS) | $(OBJDIR)
	g++ $(LIBS) -c -I . -o $@ $< -O3

KdTree: $(OBJS) | $(OBJDIR)
	g++ $(LIBS) -I . $^ -o $@ -O3

clean:
	rm -rf ./$(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)
