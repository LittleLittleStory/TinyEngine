#include "Keyboard.h"

bool Keyboard::KeyIsPressed(unsigned char keycode)const noexcept
{
	return keyStates[keycode];
}

Keyboard::Event Keyboard::ReadKey()noexcept
{
	if (keybuffer.size() > 0u)
	{
		Keyboard::Event e = keybuffer.front();
		keybuffer.pop();
		return e;
	}
	else
	{
		return Keyboard::Event();
	}
}

bool Keyboard::KeyIsEmpty()const noexcept
{
	return keybuffer.empty();
}

char Keyboard::ReadChar()noexcept
{
	if (charbuffer.size() > 0u)
	{
		unsigned char charcode = charbuffer.front();
		charbuffer.pop();
		return charcode;
	}
	else
	{
		return 0;
	}
}

bool Keyboard::CharIsEmpty()const noexcept
{
	return charbuffer.empty();
}

void Keyboard::FlushKey()noexcept
{
	keybuffer = std::queue<Event>();
}

void Keyboard::FlushChar()noexcept
{
	charbuffer = std::queue<char>();
}

void Keyboard::Flush()noexcept
{
	FlushKey();
	FlushChar();
}

void Keyboard::EnableAutorepeat()noexcept
{
	autorepeatEnable = true;
}

void Keyboard::DisableAutorepeat()noexcept
{
	autorepeatEnable = false;
}

bool Keyboard::AutorepeatIsEnable()const noexcept
{
	return	autorepeatEnable;
}

void Keyboard::OnKeyPressed(unsigned char keycode) noexcept
{
	keyStates[keycode] = true;
	keybuffer.push(Keyboard::Event(Keyboard::Event::Type::Press, keycode));
	TrimBuffer(keybuffer);
}

void Keyboard::OnKeyReleased(unsigned char keycode) noexcept
{
	keyStates[keycode] = false;
	keybuffer.push(Keyboard::Event(Keyboard::Event::Type::Release, keycode));
	TrimBuffer(keybuffer);
}

void Keyboard::OnChar(char character) noexcept
{
	charbuffer.push(character);
	TrimBuffer(charbuffer);
}

void Keyboard::ClearState() noexcept
{
	keyStates.reset();
}

template<typename T>
void Keyboard::TrimBuffer(std::queue<T>& buffer) noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}