TARGET = stu_manage
SRC_DIR = src

SOURCES  = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

%.o: %.c
	$(CC) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

all: $(TARGET)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

