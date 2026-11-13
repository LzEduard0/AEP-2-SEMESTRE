# PSE em Ação

**Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola** — tema: prevenção ao uso de álcool e outras drogas.
AEP — UNICESUMAR · Engenharia de Software e Análise e Desenvolvimento de Sistemas · 2026

## Sobre o projeto

Programa em C, executado em terminal, que ajuda a equipe intersetorial (IntegraPSE) a planejar, registrar e acompanhar ações coletivas de prevenção nas escolas do Programa Saúde na Escola (PSE). Usa só dados fictícios e coletivos: **nenhum dado individual de estudante é pedido ou guardado**, e tudo fica em memória durante a execução.

## Funcionalidades

| Opção | Funcionalidade | Requisito |
|---|---|---|
| 1 | Cadastrar ação (código, escola, tema, data, público-alvo, responsável, quantidade prevista) | RF01 |
| 2 | Listar ações | RF02 |
| 3 | Pesquisar por código, escola ou tema | RF03 |
| 4 | Atualizar situação (planejada, realizada, cancelada) | RF04 |
| 5 | Registrar ou corrigir participantes de ação realizada | RF07 |
| 6 | Resumo geral (ações por situação, participantes, percentual) | RF05 |
| 7 | Sair | — |

Validações (RF06): código duplicado ou inválido, data inexistente (DD/MM/AAAA), quantidades negativas ou nulas, opção inválida, cadastro não localizado e limite de 50 ações. O percentual de participação é calculado sobre as ações realizadas.

## Exemplo de uso

```
Digite uma opcao: 1
=== CADASTRAR ACAO ===
Digite o codigo: 101
Digite a escola: Escola Municipal Aurora
Digite o tema: Prevencao ao uso de alcool
Digite a data prevista (DD/MM/AAAA): 20/11/2026
Digite o publico-alvo: 8o ano
Digite o responsavel: Ana Souza
Digite a quantidade prevista de participantes: 40

Cadastro realizado com sucesso!
```

## Estrutura

```
src/main.c    código-fonte
docs/         documentos das duas entregas, roteiro do vídeo e imagens
tests/        testes automatizados (opcional: make test, Linux/macOS com Python 3)
```

O documento final (`docs/PSE_em_Acao_2a_Entrega.docx`) traz requisitos, fluxogramas, casos de uso, testes (23 casos aprovados), manual e considerações finais.

## Integrantes

Luiz Eduardo Santos Silva · Romulo Sotti Demito · Lucas Pescaroli Bastos
