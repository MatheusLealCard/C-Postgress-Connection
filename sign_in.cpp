#include <iostream>
#include <pqxx/pqxx>
using namespace std;

void DB_connection(){
	pqxx::connection connect("dbname=Test user=postgres password=123732dd");

	if (connect.is_open()){
		cout << "Conectado ao DB";
	}
	else{
		cout << "Nao conectado ao DB";
	}

}

int insert_data_DB(string nome, string email, string data_nascimento, bool ativo){
	pqxx::connection connect("dbname=Test user=postgres password=123732dd");

	pqxx::work C(connect);

	string query = "insert into clientes (nome, email, data_nascimento, ativo) values ('"+ nome + "', '"+ email + "', '"+ data_nascimento + "', " + (ativo ? "TRUE" : "False") + ")";
	C.exec(query);
	C.commit();
}

void find_data_DB(){
	string nome;
	cout << "Digite o usuario" << endl;
	cin >> nome;
	string senha;
	cout << "Digite sua senha" << endl;
	cin >> senha;
	pqxx::connection connect("dbname=Test user=postgres password=123732dd");
	pqxx::work C(connect);
	string query = ("select * from clientes where nome = $1 and senha = $2");
	pqxx::result R = C.exec_params(query, nome, senha);
	if (R.size() > 0){
		cout << "o usario " << nome << " existe no banco de dados";
	}
	else{
		cout << "Usuario " << nome << " nao foi encontrado";
	}
}


int main(){

	find_data_DB();
	//insert_data_DB("teste", "teste@teste", "01/01/01", "false");

}


//std::string query = "INSERT INTO clientes (nome, email, data_nascimento, ativo) VALUES ('"+ nome + "', '" + email + "', '" + data_nascimento + "', " + (ativo ? "TRUE" : "FALSE") + ")";
