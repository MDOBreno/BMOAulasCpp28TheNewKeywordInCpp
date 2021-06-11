//
//  main.cpp
//  BMOAulasCpp28TheNewKeywordInCpp
//
//  Created by Breno Medeiros on 10/06/21.
//

#include <iostream>
#include <string>

//Lembrando que 'new' instancia em um construtor(outro escopo que não é o que o new está escrito), e retorna
// um ponteiro pra instancia. Lembre-se tb que, como 'new' aloca no 'Heap', voce(desenvolvedor) é quem tem
// que se lembrar de liberar a memoria posteriormente com 'delete'.
// Obs1: Assim como o 'new' chama o construtor na alocacao, o 'delete' chama o destrutor na desalocacao.
// Obs2: Se der 'new' em um array[ Por ex "... = new Entidade[50]();" ], a desalocacao fica 'delete[]'.

using Texto = std::string;

class Entidade {
private:
    Texto m_Nome; //Cherno chuta q Texto tem cerca de 28 Bytes, mas o que importa é q o peso de Entidade==m_Nome
public:
    Entidade():
            m_Nome("Desconhecido") {
        
    }
    Entidade(const Texto& nome):
            m_Nome(nome) {
        
    }
    const Texto& GetNome() const {
        return m_Nome;
    }
};

//Esta funcao é apenas para dar uma ideia, usa-la causara erros.
void* novo(Entidade& e, int quantidadeNoArray){
    int bytesParaAlocar = sizeof(e) * quantidadeNoArray; //  1400 Bytes = 28 ByterPorEntidade * 50 Entidades
    void* retorno = malloc(bytesParaAlocar); // A funcao 'malloc()' aloca os 1400 Bytes passados, e retorna o ponteiro
    for (int i=0; i<quantidadeNoArray; i++) {
        *(&retorno + (sizeof(e) * i)) = new Entidade(); //Aqui ele chaam o construtor para cada posicao
    }
    return retorno;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a=2;
    int* b = new int;
    int* bArray = new int[50];             // Aloca: 200 Bytes = 4 BytesPorInt * 50 Ints
    
    //Obs: As duas linhas abaixo fazem sao iguais, exceto q so a primeira chama o contrutor, e por isso vc n devia a segunda:
    Entidade* eNew = new Entidade();          // Tambem funciona se nao escrever os '()'
    Entidade* eMalloc = (Entidade*)malloc(sizeof(Entidade)); // 'malloc()' aloca os Bytes passados e retorna o ponteiro
    
    Entidade* eArray = new Entidade[50](); // O bronca qnd se usa 'new' é q ele usa um bloco de 50*Entidade na memoria
    //Se fossemos escrever uma funcao do que 'new' esta fazendo na linha acima seria algo como:
    // Entidade* eArray = novo(Entidade &e, int quantidadeNoArray);             //Descomentar essa linha causa erros.
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
