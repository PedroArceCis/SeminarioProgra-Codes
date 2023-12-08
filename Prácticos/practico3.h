#include <iostream>

class Voto{
	public:
		Voto();

		void setCodigo(int cod);
		void setOpcion(int cod, int opt);

		int leer(int cod);

	private:
		int codigo;
		int opcion;
};

class Padron{
	public:
		Padron();

		~Padron();

		void sign();
		bool checkFirma();

	private:
		bool *firma;
};

class Urna{
	public:
	 	Urna(int cod_mesa, int votantes);

		~Urna();

		bool votar(int cod_voto,int opcion);
		void escrutar(int cod_mesa);

		int sufragios;

	private:
		bool sellada;
		int codigo;
		Padron *libro_firmas;
		Voto *votos;

};


