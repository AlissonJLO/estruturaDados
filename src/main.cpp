#include <iostream>
#include <array>
#include <random>

const int tamanho = 196;

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

void orderBySelection(auto &array)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[j] < array[indiceMenor])
            {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i)
        {
            std::swap(array[i], array[indiceMenor]);
        }
    }
}

void orderByBubble(auto &array)
{
    bool trocou = true;
    while (trocou)
    {
        trocou = false;
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                trocou = true;
            }
        }
    }
}

void buscaBinaria(auto &array, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio = 0;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (array[meio] == valor)
        {
            std::cout << "Valor encontrado na posição: " << meio << std::endl;
            return;
        }
        else if (array[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    std::cout << "Valor não encontrado" << std::endl;
}

int main()
{
    std::array<int, tamanho> array;

    preencherArray(array);
    exibirArray(array);
    /* orderByInsertion(array);
    orderBySelection(array);
    buscaLinear(array, 10);
    exibirArray(array);
    */
    orderByBubble(array);
    buscaBinaria(array, 10);

    return 0;
}
