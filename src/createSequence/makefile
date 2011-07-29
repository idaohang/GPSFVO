#shell commands
ECHO = @echo
RM = @rm
RMFLAGS = -f


#Compiling and linking
COMPILER = @g++
COMPILERFLAGS = -c -Wall
LINKER = @g++
LINKERFLAGS =

#Project
TARGET = createSequence
OBJECTS = main.o parser.o gpsData.o timeReference.o sequenceGenerator.o
INCLUDEPATHS = -I../lib/buffToBMP/
LIBSPATHS = -L../lib/bin/
LIBS = -lbuffToBMP

all : $(TARGET)

#Linking
$(TARGET) : $(OBJECTS)
	$(ECHO) "-- Linking $(TARGET)... (Because of : $?)"
	$(LINKER) $(LINKERFLAGS) -o $(TARGET) $(OBJECTS) $(LIBSPATHS) $(LIBS)
	$(ECHO) "-- $(TARGET) was successfully built"

#Compiling
%.o : %.cpp
	$(ECHO) "-- Compiling $< ... (Because of : $?)"
	$(COMPILER) $(COMPILERFLAGS) $(INCLUDEPATHS) $<

#Per file dependency
main.o : parser.h timeReference.h
parser.o : parser.h gpsData.h timeReference.h
gpsData.o : gpsData.h timeReference.h
timeReference.o : timeReference.h
sequenceGenerator.o : 

#Helpers
run : all
	$(ECHO) "-- Launching $(TARGET) ..."
	./$(TARGET) 
	$(ECHO) "-- $(TARGET) terminated ..."

debug : all
	$(ECHO) "-- Launching $(TARGET) With error trace..."
	./$(TARGET) 2> debug
	$(ECHO) "-- $(TARGET) terminated. Showing error trace..."
	@cat debug


#Cleaning
clean : 
	$(ECHO) "-- Cleaning $(TARGET)"
	$(RM) $(RMFLAG) *.o $(TARGET) 
