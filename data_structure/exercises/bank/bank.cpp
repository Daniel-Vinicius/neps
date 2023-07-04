#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int n_caixas, n_clientes;
  cin >> n_caixas >> n_clientes;

  if (n_caixas >= n_clientes)
  {
    cout << 0 << endl;
    return 0;
  }

  // crio uma fila de prioridade em que o topo sempre será o menor tempo em que um atendimento é finalizado
  priority_queue<int, vector<int>, greater<int>> caixa;

  int tempoCaixaLivre = 0, clientesIrregulares = 0;
  int entrada, duracao;

  for (int i = 0; i < n_caixas; i++)
  {
    cin >> entrada >> duracao;
    caixa.push(entrada + duracao);
  }

  for (int i = n_caixas; i < n_clientes; i++)
  {
    cin >> entrada >> duracao;

    tempoCaixaLivre = caixa.top();
    caixa.pop();

    // São irregulares os clientes que esperarem mais de 20 minutos na fila
    if (tempoCaixaLivre - entrada > 20)
    {
      clientesIrregulares++;
    }

    // pode ter um tempo em que não havia clientes, por isso é preciso pegar o máximo entre o tempo que o caixa ficou livre e o tempo de entrada do cliente
    // adicionado a duracao e atualizando assim o tempo que o caixa vai ficar livre
    caixa.push(max(tempoCaixaLivre, entrada) + duracao);
  }

  cout << clientesIrregulares << endl;

  return 0;
}