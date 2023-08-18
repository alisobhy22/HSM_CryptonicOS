CC = gcc
CFLAGS = -Wall


SRCS = ./GeneratedFiles/OsGenerated.c ./Sources/APIs_Sources/Events.c ./Sources/APIs_Sources/OSExecutionControl.c ./Sources/APIs_Sources/OsTasks.c ./Sources/APIs_Sources/Resources.c ./Sources/APIs_Sources/Tasks.c
OBJS = $(SRCS:.c=.o)

#Enviroment_Testing
SRCS_Main = ./Tests/Enviroment/main.c 
OBJS_Main = $(SRCS_Main:.c=.o)

#Event_Testing
SRCS_ClearEvents = ./Tests/Events/ClearEvent.c  
OBJS_ClearEvents = $(SRCS_ClearEvents:.c=.o)
SRCS_GetEvent = ./Tests/Events/GetEvent.c  
OBJS_GetEvent = $(SRCS_GetEvent:.c=.o)
SRCS_SetEvent = ./Tests/Events/SetEvent.c  
OBJS_SetEvent = $(SRCS_SetEvent:.c=.o)
SRCS_WaitEvent = ./Tests/Events/WaitEvent.c  
OBJS_WaitEvent = $(SRCS_WaitEvent:.c=.o)

INCLUDES = -IHeaders -IConfigurations

LIBS =
main: $(OBJS) $(OBJS_Main) $(OBJS_ClearEvents) $(OBJS_GetEvent) $(OBJS_SetEvent) $(OBJS_WaitEvent)
	$(CC) $(CFLAGS) $(INCLUDES) -o main $(OBJS) $(OBJS_Main) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o ClearEvent $(OBJS) $(OBJS_ClearEvents) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o GetEvent $(OBJS) $(OBJS_GetEvent) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o SetEvent $(OBJS) $(OBJS_SetEvent) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o WaitEvent $(OBJS) $(OBJS_WaitEvent) $(LIBS)
		
clean:
	del main.exe
	del .\Tests\Enviroment\main.o

	del ClearEvent.exe
	del .\Tests\Events\ClearEvent.o
	del GetEvent.exe
	del .\Tests\Events\GetEvent.o
	del SetEvent.exe
	del .\Tests\Events\SetEvent.o
	del WaitEvent.exe
	del .\Tests\Events\WaitEvent.o

	del .\GeneratedFiles\OsGenerated.o
	del .\Tests\Enviroment\main.o
	del .\Sources\APIs_Sources\Events.o
	del .\Sources\APIs_Sources\OSExecutionControl.o
	del .\Sources\APIs_Sources\OsTasks.o
	del .\Sources\APIs_Sources\Resources.o
	del .\Sources\APIs_Sources\Tasks.o


