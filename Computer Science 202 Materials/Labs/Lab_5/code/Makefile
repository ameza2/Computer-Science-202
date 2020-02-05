TARGET = test_ComplexNumber
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall -std=c++11 #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o ComplexNumber.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o ComplexNumber.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp ComplexNumber.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

ComplexNumber.o: ComplexNumber.cpp ComplexNumber.h
	$(CXX) $(CXX_FLAGS) -c ComplexNumber.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
