#include "Adapter.h"

#include <string>

Adapter::Adapter() { }

string Adapter::format() {
	return " онец игры, если хотите поддержать разработку данного проэкта вот ссылка на патрион(/****) в будущем планируетьс€ сделать сайт с насто€щим казино и преображение графического интерфейса, и возмножно игра будет переписанна € €зыке Piton, множество планов в общем\n";
}

void Adapter::prettyPrint(const Deck& formatDeck) {
	cout << "\x1b[33m\n" << Adapter::format() << "\t\x1b[0m";
}