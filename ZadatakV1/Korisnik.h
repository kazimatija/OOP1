#ifndef KORISNIK_H
#define KORISNIK_H

#include <string>
#include <iostream>

class Korisnik {
	std::string ime;
	std::string email;

public:
	Korisnik(std::string i, std::string e) :ime(i), email(e) {}
	Korisnik(const Korisnik&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	
	std::string dohvIme() { return ime; }
	std::string dohvEmail() { return email; }

	friend std::ostream& operator<<(std::ostream&, const Korisnik&);
};

#endif KORISNIK_H