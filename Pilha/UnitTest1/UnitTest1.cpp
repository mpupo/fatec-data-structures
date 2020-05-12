#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/pilha.h"
#include <string>
#include <iostream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Palindroma1)
		{
			Stack<std::string> pilha = Stack<std::string>(50);
			std::string frase("ovo");

			pilha.insertPhrase(frase);
			Assert::IsTrue(pilha.sao_palindromos(frase));
		}

		TEST_METHOD(ComEspacos)
		{
			Stack<std::string> pilha = Stack<std::string>(50);
			std::string frase("SOCORRAM-ME, SUBI NO ONIBUS EM MARROCOS");

			pilha.insertPhrase(frase);
			Assert::IsTrue(pilha.sao_palindromos(frase));
		}
	};
}
