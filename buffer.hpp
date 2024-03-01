// buffer.hpp - заголовочный файл с описанием класса Buffer

#ifndef BUFFER_HPP
#define BUFFER_HPP

	class Buffer 
	{
		/* Класс Buffer управляет выделением памяти для буфера 
			и размещением в нём данных ------------------------ */
		
		private:
		
			char *m_pbuffer;		// Указатель на выделенную аллокатором область памяти
			unsigned int m_size; // Размер выделенной области памяти
			unsigned int length; // Размер памяти, которую на данный момент заполняют данные
		
		public:
		
			/* Конcтрукторы и деструкторы класса (buffer.cpp) */
			
				Buffer();
				Buffer(unsigned int size);
				Buffer(const Buffer & buffer);
				Buffer(const char *buf, unsigned int size);			
				virtual ~Buffer();
				
			/* Селекторы класса */
			
				int getSize() const { return m_size; }
				int getLength() const { return length; }
				const char *getBuffer() const { return m_pbuffer; }
				
			/* Модификаторы класса */
			
				void setSize(unsigned int size);                    // setsize.cpp
				void setBuffer(const Buffer & buffer);              // setbuffer.cpp
				void setBuffer(const char *buf, unsigned int size); // setbuffer.cpp
				
			/* Другие методы класса */
			
				void add(const char *p_data, int size); // add.cpp
				void clear();									 // buffer.cpp							
				void reset();									 // buffer.cpp
		
	}; // class Buffer

#endif // BUFFER_HPP
