#include "Adapter.h"

#include <string>

Adapter::Adapter() { }

string Adapter::format() {
	return "����� ����, ���� ������ ���������� ���������� ������� ������� ��� ������ �� �������(/****) � ������� ������������ ������� ���� � ��������� ������ � ������������ ������������ ����������, � ��������� ���� ����� ����������� � ����� Piton, ��������� ������ � �����\n";
}

void Adapter::prettyPrint(const Deck& formatDeck) {
	cout << "\x1b[33m\n" << Adapter::format() << "\t\x1b[0m";
}