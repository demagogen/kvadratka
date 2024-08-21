CC=g++

WORK_CATALOG=kvadratka
COMPILE_DIR=compile
OBJECTS_DIR=builddir
OUTFILE=kvadratka
SOURCES_DIR=sourcers
HEADERS_DIR=headers
HEADER_FILES=enter_print.h solve_square_equation.h utils.h structures.h
OBJECT_FILES=main.o enter_print.o solve_square_equation.o utils.o
SOURCES=main.cpp enter_print.cpp solve_square_equation.cpp utils.cpp

CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

all: $(OUTFILE)

$(OUTFILE): $(COMPILE_DIR)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(OUTFILE)
	mkdir $(OBJECTS_DIR)
	mv $(OBJECT_FILES) $(OBJECTS_DIR)

$(COMPILE_DIR):
	$(CC) $(CFLAGS) -c $(SOURCES)
	mkdir $(SOURCES_DIR)
	mv $(SOURCES) $(SOURCES_DIR)

$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)
	mv $(OBJECT_FILES) $(OBJECTS_DIR)

$(HEADERS_DIR):
	mkdir $(HEADERS_DIR)
	mv $(HEADER_FILES) $(HEADERS_DIR)

clean:
	rm -rf $(OBJECTS_DIR)
	cp -rf $(SOURCES_DIR)/* ./
	rm -rf $(SOURCES_DIR)
	rm -rf *.o $(OUTFILE)
	cp -rf $(HEADERS_DIR)/* ./
	rm -rf $(HEADERS_DIR)
