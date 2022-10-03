<div><img src="https://game.42sp.org.br/static/assets/images/42-saopaulo.png" height=80>
<img src="https://game.42sp.org.br/static/assets/achievements/so_longe.png" align="right" height=100></div>

<br>

# SO_LONG
Entregando...<br>
consultar [SO_LONG_V1](https://github.com/leogremes/42SP_so_long_v1) para ver a primeira versão do projeto

## Sobre
O objetivo deste projeto era desenvolver um jogo simples onde um personagem deve coletar alguns itens pelo
mapa e ir para a saída. O jogo deve atender uma série de especificações e devemos utilizar a <b>minilibx</b>
que é a biblioteca que permite criar uma janela e interagir com ela. Além disso poderíamos utilizar
a nossa <b>[LIBFT](https://github.com/leogremes/42SP_libft)</b> e o nosso
<b>[FT_PRINTF](https://github.com/leogremes/42SP_ft_printf)</b>.

## Desenvolvimento
Mais uma vez eu optei por não utilizar a libft inteira, eu reescrevi do zero só as funções que eu
precisei utilizar e também não precisei de utilizar o ft_printf.

Para rodar o programa ele deve ser chamado passando como argumento um nome de um arquivo .ber referente ao mapa.
Exemplo:
		
		./so_long small.ber

Ao ser iniciado, o programa fará as seguintes verificações:
- Número de argumentos passados
- Se o argumento corresponde a um arquivo .ber
- se o arquivo existe
- Se o mapa contém todos os requisitos (1 saída, 1 posição inicial e 1+ coletáveis)
- Se o mapa é retangular
- Se o mapa é cercado por paredes
- se o mapa contém caractéres inválidos
- Se existe um caminho válido no mapa

Caso qualquer uma das verificações apresentem erros, o programa é abortado. Em caso positivo
o programa irá inicial a minilibx, criar a janela e buscar as imagens dos sprites.

Para o jogo funcionar, temos 3 funções importantes. A primeira é a responsável por desenhar as imagens,
percorrendo cada elemento do mapa e imprimindo a imagem correspondente na tela. A segunda é responsável
pelo gerenciamento do aperto de teclas, movendo o jogador e/ou fechando a janela. A útlima é responsável
por fechar a janela caso o usuário clique no botão 'X'.

Para fazer a animação dos sprites eu usei uma <b>lista encadeada</b>, onde cada nó da lista contém as imagens
referentes a um estado da animação e a cada certo número de vezes que a tela é lida o ponteiro das imagens aponta
pro pŕoximo nó da lista.

Ao final do jogo, é exibida uma mensagem de vitória, derrota ou jogo fechado pelo usuário e o programa libera todas
as memórias e fecha.

## Mudanças em relação ao projeto original
O escopo projeto sofreu uma alteração dia 19/09/2022 e passou a ser obrigatório verificar
se existe um caminho válido no mapa, além de apresentar erro caso haja mais de uma saída ou
posição inicial (antes era indefinido).

Eu optei por reescrever o projeto, mas aprovitando muitos dos códigos da primeira versão.

As principais diferenças desta versão para a original são:
- Adicionado algorítmo para a verificação de caminho (uma espécie de DFS, utilizando função recursiva).
- Inimigos agora ficam parados (devido a complexidade de verificar caminho com inimigos que se movem).
- sprites menores (agora são de 32x32, para lidar melhor com mapas maiores).
- Mudança de tema (aproveitei que ia mudar os sprites e escolhi um tema mais pŕoximo ao que eu qureia).
- Contador para a animação incrementa a cada <i>tile</i> lido. (Para diminuir a diferença de animação entre mapas pequenos e grandes).
- Uma pequena mudança na forma de liberar memórias e fechar o programa.

## Aprendizado
Este projeto não apresentou muito conteúdo novo, mas os principais aprendizados foram:
- função <b><i>exit</i></b> (encerra o programa em qualquer momento).
- funções <i><b>perror</b></i> e <i><b>strerror</b></i> (Não usei, mas pesquisei sobre elas pois estavam no escopo).
- <b>criação e manipulação de janelas</b> (através da minilibx, mas acredito que seja uma boa base).

Uma dificuldade que tive que superar é que os projetos começam a ficar extensos e complexos, também tive a
oportunidade de explorar bastante o uso das <b><i>structs</i></b> e das <b>listas encadeadas</b>.

## Impressões Pesoais
Este é o quinto projeto da 42 e até agora foi o mais divertido de fazer apesar de ter sido um projeto
considerávelmente maior que os já feitos até aqui.
Ver o resultado do projeto, por mais simples que seja, é muito satisfatório e traz a sensação de que
valeu a pena.

### Confira outros projetos desenvolvidos por mim na formação da 42 São Paulo
1. [LIBFT](https://github.com/leogremes/42SP_libft)
2. [GET_NEXT_LINE](https://github.com/leogremes/42SP_gnl)
3. [FT_PRINTF](https://github.com/leogremes/42SP_ft_printf)
4. BORN2BEROOT (Projeto não consiste em códigos)
5. SO_LONG [[V1]](https://github.com/leogremes/42SP_so_long_v1) <b>[V2]</b>
