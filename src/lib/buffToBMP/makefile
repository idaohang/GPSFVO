#shell commands
ECHO = @echo
CP = @cp
MKDIR = @mkdir -p -v
RM = @rm
RMFLAGS = -f

#Compiling and linking
COMPILER = @gcc
COMPILERFLAGS = -c -Wall
LIBMAKER = @ar
LIBMAKERFLAGS = rcs

#Project
TARGET = libbuffToBMP.a
OBJECTS = buffToBMP.o
INCLUDEPATHS = 
LIBBINPATHS = ../bin/

all : $(TARGET)

#Linking
$(TARGET) : $(OBJECTS)
	$(ECHO) "-- Linking $(TARGET)... (Because of : $?)"
	$(LIBMAKER) $(LIBMAKERFLAGS) $(TARGET) $(OBJECTS)
	$(ECHO) "-- $(TARGET) was successfully built"
	$(ECHO) "-- Copying $(TARGET) to $(LIBBINPATHS) directory..."
	$(MKDIR) $(LIBBINPATHS)
	$(CP) $(TARGET) $(LIBBINPATHS)

#Compiling
%.o : %.c
	$(ECHO) "-- Compiling $< ... (Because of : $?)"
	$(COMPILER) $(COMPILERFLAGS) $(INCLUDEPATHS) $<

#Per file dependency
buffToBMP.o : buffToBMP.h

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
