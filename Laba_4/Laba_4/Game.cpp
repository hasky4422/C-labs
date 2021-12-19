#include "Game.h"

Game::Game() {

	for (int i = 0; i < 4; i++)
	{
		deck[i] = new Deck();
		deck[i]->shuffle();
	}
	player = new Player();
	dealer = new Dealer();
}

Game::~Game() {

	for (int i = 0; i < 4; i++) delete deck[i];
	delete player;
	delete dealer;
}

void Game::play() {

	int size = 0;
	cout << "2 �������\n --> ���: �����������\n --> ���.�������: ����\n";
	cout << "\n��� ������: " << player->getBalance();
	cout << "\x1b[33m$\n\x1b[0m" << "\x1b[31m���� ������?\x1b[0m" << endl;
	cin >> bet;

	dealer->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	player->addCard(deck[rand() % 4]->pop());
	while (match) partGame();
}

void Game::printGame() {

	cout << "\x1b[33m\n������:\t\x1b[0m";
	for (int i = 0; i < 4; i++) {
		cout << "[" << deck[i]->getSize() << "]\t";
	}
	cout << "\x1b[32m\n�����:\t\x1b[0m";
	for (int i = 0; i < dealer->getHand()->getCards().size(); i++) {
		cout << *dealer->getHand()->getCards().at(i) << "\t";
	}
	cout << "\x1b[31m\n��:\t\x1b[0m";
	for (int i = 0; i < player->getHand()->getCards().size(); i++) {
		cout << *player->getHand()->getCards().at(i) << "\t";
	}
}

void Game::partGame() {

	playerScore = player->getHand()->getScore();
	if (playerScore == 21 && player->getHand()->getCards().size() == 2) {
		blackJack();
	}
	else {
		printGame();
		if (player->getHand()->getCards().size() == 2 && isDouble == true) menuDoubles();
		else menu();
	}
}

void Game::menu()
{
	cout << "\n1. ������\n2. ���\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) stop();
	else if (item == 2) more();
	else cout << "�� ��������!\n";
}

void Game::menuDoubles()
{
	cout << "\n1. ������\n2. ���\n3. ����\n";
	cin >> item;
	dealerScore = dealer->getHand()->getScore();
	playerScore = player->getHand()->getScore();
	if (item == 1) stop();
	else if (item == 2) more();
	else if (item == 3) doubles();
	else std::cout << "�� ��������!\n";
}

void Game::conditionMaxCard()
{
	if (player->getHand()->getCards().size() == 5 && player->getHand()->getScore() < 21) {
		bet *= 1.5;
		win();
	}
	else if (player->getHand()->getCards().size() == 6 && player->getHand()->getScore() < 21) {
		bet *= 2;
		win();
	}
	else if (player->getHand()->getCards().size() == 7 && player->getHand()->getScore() < 21) {
		bet *= 3;
		win();
	}
}

void Game::more() {

	try {
		player->addCard(deck[rand() % 4]->pop());
		playerScore = player->getHand()->getScore();
		conditionMaxCard();
		if (playerScore > 21) throw true;
	}
	catch (...) {
		printGame();

		cout << "\n�������! �� ���������! ��� ��������: " << bet <<". ��� ������: " << player->getBalance() - bet << endl;

		player->clearHand();
		dealer->clearHand();

		match = false;
	}
}

void Game::stop() {

	dealer->addCard(deck[rand() % 4]->pop());
	dealerScore = dealer->getHand()->getScore();

	if (dealerScore >= 21) win();
	if (dealerScore < playerScore) win();
	if (dealerScore < 21 && dealerScore >= playerScore) losing();
}

void Game::doubles() {
	bet *=2;
	more();
	cout << "\n���� ������ ������: " << bet << endl;
	isDouble = false;
}

void Game::losing() {
	printGame();

	player->clearHand();
	dealer->clearHand();

	cout << "\n�� ���������! ��� ��������: " << bet << ". ��� ������: " << player->getBalance() - bet << endl;
	match = false;
}

void Game::win() {

	printGame();

	player->addMoney(bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\n�����������! �� ��������! ��� �������: " << bet << ". ��� ������: " << player->getBalance() << endl;
	match = false;
}

void Game::blackJack() {
	printGame();

	player->addMoney(1.5 * bet);
	player->clearHand();
	dealer->clearHand();

	cout << "\n�����������! � ��� ���� ����! ��� �������: " << bet*1.5 << ".  ��� ������: " << player->getBalance() << endl;
	match = false;
}