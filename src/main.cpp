#include <iostream>
#include <array>
#include <random>

const int tamanho = 10;

// Função para preencher o array com números aleatórios
void preencherArray(auto &array)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    // Preenchendo o array com números aleatórios
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = dis(gen);
    }
}

// Função para exibir o array
void exibirArray(const auto &array)
{
    std::cout << "Array gerado: ";
    for (const auto &elem : array)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void orderByInsertion(auto &array)
{

    auto aux = 0;
    for (int i = 1; i < tamanho; i++)
    {
        auto j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j = j - 1;
        };
    };
}

void buscaLinear(auto &array, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] == valor)
        {
            std::cout << "Valor encontrado na posição: " << i << std::endl;
            return;
        }
    }
    std::cout << "Valor não encontrado" << std::endl;
}

int main()
{
    std::array<int, tamanho> array;

    // Preencher e exibir o array
    preencherArray(array);
    exibirArray(array);
    orderByInsertion(array);
    exibirArray(array);
    buscaLinear(array, 10);

    return 0;
}
