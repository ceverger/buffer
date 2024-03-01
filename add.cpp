// add.cpp - реализация метода add.cpp класса Buffer

#include "buffer.hpp"

	void Buffer::add(const char *buffer, int size)
	{
		/* Добавление новых данных в буфер */
		
			if(buffer == nullptr || size == 0) return;
			
			if(m_size == 0)
			{
				/* Если буфер пустой и память для него не
					выделена, выделяем её, записывем в неё
					данные и выходим из метода ----------- */
					
					setBuffer(buffer, size);
					
					return;
			}
				
			if(m_size < length + size)
				{
					/* Если памяти буфера не хватает, чтобы
						добавить новые данные, то выделяем нужное
						количество памяти ----------------------- */
						
						m_size = length + size;
						setSize(m_size);						
				}
								
			/* Дозаписывваем данные в буфер */
			
				for(unsigned int i = length; i < length + size; ++i)
					m_pbuffer[i] = buffer[i];
				
				length += size;
	}
