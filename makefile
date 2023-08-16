CC = gcc
CFLAGS = -Wall

SRCS = ./Tests/Enviroment/main.c ./GeneratedFiles/OsGenerated.c ./Sources/APIs_Sources/Events.c ./Sources/APIs_Sources/OSExecutionControl.c ./Sources/APIs_Sources/OsTasks.c ./Sources/APIs_Sources/Resources.c ./Sources/APIs_Sources/Tasks.c
OBJS = $(SRCS:.c=.o)

INCLUDES = -IHeaders -IConfigurations

LIBS =

main: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o main $(OBJS) $(LIBS)

clean:
	del main.exe
	del .\Tests\Enviroment\main.o
	del .\GeneratedFiles\OsGenerated.o
	del .\Tests\Enviroment\main.o
	del .\Sources\APIs_Sources\Events.o
	del .\Sources\APIs_Sources\OSExecutionControl.o
	del .\Sources\APIs_Sources\OsTasks.o
	del .\Sources\APIs_Sources\Resources.o
	del .\Sources\APIs_Sources\Tasks.o


