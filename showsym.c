// Template to complete the loadfunc program which locates a function
// in the text section of an ELF file. Sections that start with a
// CAPITAL in their comments require additions and modifications to
// complete the program (unless marked as PROVIDED).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>

// macro to add a byte offset to a pointer
#define PTR_PLUS_BYTES(ptr,off) ((void *) (((size_t) (ptr)) + ((size_t) (off))))

// address at which to map the ELF file
#define MAP_ADDRESS  ((void *) 0x0000600000000000)

int main(int argc, char **argv){
  // PROVIDED: command line checks for proper # args
  if(argc < 2){                 
    printf("usage: %s <file>\n",argv[0]);
    return 0;
  }

  // PROVIDED: required command line arguments
  char *objfile_name = argv[1]; // name of file to operate  on
                        
  // PROVIDED: open file to get file descriptor, determine file size
  int fd = 0L;                  // open file to get file descriptor
  struct stat stat_buf;         // call fstat() to fill in fields like size of file
  0;                            // ??? 
  int file_size = 0;            // ???

  // CREATE memory map via mmap() call, ensure that pages are readable
  // AND executable. Map to virtual address MAP_ADDRESS, first arg to mmap().
  char *file_bytes =                         // pointer to file contents
    NULL; /// ???;

  // CHECK for failure in memory map, print message and return 1 if
  // failed; otherwise, print pointer value of memory map
  if(file_bytes == 0){ /// ???
    printf("ERROR: failed to mmap() file %s\n",objfile_name);
    return 1;
  }
  printf("file_bytes at: %p\n",file_bytes);

  // CREATE A POINTER to the intial bytes of the file which are an ELF64_Ehdr struct
  Elf64_Ehdr *ehdr = NULL; /// ???

  // CHECK e_ident field's bytes 0 to for for the sequence {0x7f,'E','L','F'}.
  // Exit the program with code 1 if the bytes do not match
  int magic_match =
    0; /// ???

  if(!magic_match){
    printf("ERROR: Magic bytes wrong, this is not an ELF file\n");
    return 1;
  }

  // PROVIDED: check for a 64-bit file
  if(ehdr->e_ident[EI_CLASS] != ELFCLASS64){
    printf("ERROR: Not a 64-bit file ELF file\n");
    return 1;
  }

  // PROVIDED: check for x86-64 architecture
  if(ehdr->e_machine != EM_X86_64){
    printf("ERROR: Not an x86-64 file\n");
    return 1;
  }
  // could check hear for ehdr->e_ident[EI_OSABI] for ELFOSABI_LINUX


  // SET UP a pointer to the array of section headers.  Determine the
  // offset of the Section Header Array (e_shoff) and the number of
  // sections (e_shnum). These fields are from the ELF File
  // Header. The print accroding to the format below
  Elf64_Shdr *shdr = NULL; /// ???
  printf("Section Headers Found:\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %hu sections total\n",0); /// ???
  printf("- %p section header virtual address\n", NULL); /// ???

  // SET UP a pointer to the Section Header String Table
  // .shstrtab. Find the its section index in the ELF header with the
  // fiel (e_shstrndx).  The index into the array of section headers
  // to find the position in the file and set up a pointer to it. See
  // the spec diagram for a visual representation.
  uint16_t shstrndx = 0; /// ???
  char *shstrab = NULL; /// ???
  printf("Section Header Names in Section %d\n",0); /// ???
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu total bytes\n", 0L); /// ???
  printf("- %p .shstrtab virtual address\n",NULL); /// ???

  // SEARCH the Section Header Array for sections with names .symtab
  // (symbol table) and .strtab (string table).  Note their positions
  // in the file (sh_offset field).  Also note the size in bytes
  // (sh_size) and and the size of each entry (sh_entsize) for .symtab
  // so its number of entries can be computed.
  Elf64_Shdr *symtab_sh = NULL;
  Elf64_Shdr *strtab_sh = NULL;

  printf("\n");
  printf("Scanning Section Headers for Relevant Sections\n");
  for(int i=0; i<0; i++){   /// ???
    char *secname = NULL;
    printf("[%2d]: %s\n",i,secname);
    // CHECK for .symtab
    // CHECK for .strtab
  }

  printf("\n");

  // CHECK that the symbol table was found; if not, error out. SET UP
  // a pointer to the .symtab section and print information as shown.
  if(symtab_sh == NULL){
    printf("ERROR: Couldn't find symbol table\n");
    return 1;
  }
  uint64_t symtab_num = 0L; /// ???
  Elf64_Sym *symtab = NULL; /// ???
  printf(".symtab located\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu bytes total size\n",0L); /// ???
  printf("- %lu bytes per entry\n",0L); /// ???
  printf("- %lu number of entries\n",0L); /// ???
  printf("- %p .symtab virtual addres\n",NULL); /// ???


  // CHECK that .strtab (string table) section is found. Error out if
  // not. SET UP a pointer to it and print information as shown.
  if(strtab_sh == NULL){
    printf("ERROR: Couldn't find .strtab section\n");
    return 1;
  }
  char *strtab = NULL;
  printf(".strtab located\n");
  printf("- %lu bytes from start of file\n",0L); /// ???
  printf("- %lu total bytes in section\n",  0L); /// ???
  printf("- %p .strtab virtual addres\n",NULL); /// ???

  printf("\n");
  printf("SYMBOL TABLE CONTENTS\n");
  printf("[%3s]  %8s %4s %s\n","idx","TYPE","SIZE","NAME");

  // ITERATE through the symbol table (.symtab section), an array of
  // Elf64_Sym structs. Print the contents of each entry according to
  // the following format:
  // 
  // SYMBOL TABLE CONTENTS
  // [idx]      TYPE SIZE NAME
  // [  0]:   NOTYPE    0 <NONE>
  // [  1]:     FILE    0 x.c
  // [  2]:  SECTION    0 <NONE>
  // [  3]:  SECTION    0 <NONE>
  // [  4]:  SECTION    0 <NONE>
  // [  5]:  SECTION    0 <NONE>
  // [  6]:  SECTION    0 <NONE>
  // [  7]:  SECTION    0 <NONE>
  // [  8]:   OBJECT  512 arr
  // [  9]:     FUNC   17 func
  for(uint64_t i=0; i<symtab_num; i++){
    // LOCATE the name of the symbol and print it or <NONE> if no name
    // has length 0
    // 
    // USE MACRO ELF64_ST_TYPE() on symtable_entry[i].st_info to
    // determine and print its type. This will involve a sequence of
    // if/else statements or a switch()
    //
    // FIND THE SIZE of the symbol which is in a field of the symbol
    // table entry. Consult the documentation for the struct, perhaps
    // by typing `man elf` in a terminal and searching for the
    // Elf64_Sym struct documentation.
  }

  printf("\n");

  // Close open file and unmap mmap()'d memory
  0; // ???

  return 0;
}
