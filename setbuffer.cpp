/* setbuffer.hpp - реализация модификаторов:
						 void setBuffer(const Buffer & buffer) и
						 void setBuffer(const char *buf, int size) 
						 класса Buffer --------------------------  */
						 
#include "buffer.hpp"

	void Buffer::setBuffer(const Buffer & buffer)
		{
			/* Копирование объекта буфера */
			
				if(buffer.m_size == 0) return;
			
				if(m_size > 0) reset();
				
				m_pbuffer = new char[buffer.m_size];
				m_size = buffer.m_size;
				
				if(buffer.length == 0) return;
				
				length = buffer.length;
					
				for(unsigned int i = 0; i < length; ++i)
					m_pbuffer[i] = buffer.m_pbuffer[i];
		}
		
	void Buffer::setBuffer(const char *buffer,  unsigned int size)
		{
			/* Копирование в буфер новых данных и выделение
				памяти для них, если потребуется ----------- */
			
				if(buffer == nullptr || size == 0) return;
				
				if(m_size == 0)
				{
					/* Если память для буфера еще не выделенна
						то выделяем её ------------------------- */
						
						m_pbuffer = new char[size];
						m_size = size;
				}
				
				if(m_size < size)
				{
					/* Если память для буфера была ранее выделена,  
						но её недостаточно для размещения данных, 
						то выделяем нужное количество ------------ */
						
						delete [] m_pbuffer;
						m_pbuffer = new char[size];
						m_size = size;						
				}
				
				clear();				
				length = size;
				
			/* Копирование данных в буфер */
				
				for(unsigned int i = 0; i < length; ++i)
					m_pbuffer[i] = buffer[i];				
		}	

	
						 
