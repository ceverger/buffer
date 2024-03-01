// buffer.hpp - файл исходного кода с реализацией конструкторов,
//					 деструкторов и некоторых других методов класса Buffer

#include "buffer.hpp"

	Buffer::Buffer()
	{
		/* Реализация конструктора класса по умолчанию */
		
			m_pbuffer = nullptr;
			m_size = 0;
			length = 0;
	}
	
	Buffer::Buffer(unsigned int size)
	{
		/* Релизация пользовательского конструктора (version 1) */
		
			if(size == 0) return;
			
			m_pbuffer = new char[size];
			m_size = size;
			length = 0;
			
			clear();
	}
		
	Buffer::Buffer(const char *buffer, unsigned int size)
	{
		/* Релизация пользовательского конструктора (version 2) */
		
			if(buffer == nullptr || size == 0) return;
			
			m_pbuffer = new char[size];
			m_size = size;
			length = 0;
			
			clear();
	}
		
	Buffer::Buffer(const Buffer & buffer)
	{
		/* Релизация конструктора копирования */
		
			if(buffer.m_size == 0) return;
			
			m_pbuffer = new char[buffer.m_size];
			m_size = buffer.m_size;
			length = buffer.length;
				
			for(unsigned int i = 0; i < m_size; ++i)
				m_pbuffer[i] = buffer.m_pbuffer[i];
	}
	
	Buffer::~Buffer()
	{
		/* Релизация деструктора по умолчанию */
		
			delete [] m_pbuffer;
	}
	
	void Buffer::clear()
	{
		/* Очистка буфера от данных */
		
			for(unsigned int i = 0; i < m_size; ++i) 
				m_pbuffer[i] = '\0';
			
			length = 0;
	}
	
	void Buffer::reset()
	{
		/* Сброс буфера (освобождение памяти буфера) */
		
			delete [] m_pbuffer;
			
			m_pbuffer = nullptr;
			m_size = 0;
			length = 0;
	}
