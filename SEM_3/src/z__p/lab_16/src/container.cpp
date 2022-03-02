#include "container.h"
#include <iostream>

int MEM_MAX = 100;

int Container::mem_size = 0;
Container *Container::mem_ptr = nullptr;

void *Container::operator new(size_t value) throw()
{
  if (mem_size == MEM_MAX)
  {
    std::cout << "Max size reached" << std::endl;
    throw;
  }

  if (mem_size == 0)
  {
    std::cout << "Pierwszy obiekt na stercie - alokuje kontener na " << MEM_MAX << " elementow" << std::endl;
    new Container[MEM_MAX];
  }

  mem_size++;
  mem_ptr[mem_size - 1].value() = value;

  return &mem_ptr[mem_size - 1];
}

void *Container::operator new[](size_t size)
{
  if (mem_size == MEM_MAX)
  {
    std::cout << "Max size reached" << std::endl;
    throw;
  }

  if (mem_size == 0)
    mem_ptr = (Container *)calloc(sizeof(Container), MEM_MAX);

  mem_size += size;

  return &mem_ptr[mem_size - size];
}

Container::~Container()
{
  mem_size--;
  std::cout << " --- Zwalniam 1 --- Wolne miejsca: " << std::endl;

  if (mem_size == 0)
  {
    std::cout << "Ostatni obiekt na stercie, zwalnia kontener" << std::endl;
    free(mem_ptr);
  }
}