# 🐦 Pássaro Voador (Flappy Bird)

Um clone do famoso jogo Flappy Bird desenvolvido em C++ para console Windows. Controle um pássaro que deve passar por obstáculos (canos) sem colidir com eles.

## 📋 Descrição

Este é um clone do icônico jogo Flappy Bird, implementado inteiramente em C++ usando apenas a interface de console do Windows. O jogador controla um pássaro que deve voar através de uma série de canos com aberturas, evitando colisões. A física da gravidade faz o pássaro cair constantemente, e o jogador deve pressionar a tecla de espaço para fazê-lo subir.

## 🎮 Sobre o Flappy Bird

Flappy Bird foi um jogo mobile viral criado por Dong Nguyen em 2013. Conhecido por sua simplicidade viciante e alta dificuldade, o jogo se tornou um fenômeno cultural. Este projeto recria a mecânica principal do jogo usando gráficos ASCII no console.

## ✨ Características

- 🎯 Mecânica fiel ao Flappy Bird original
- 📊 Sistema de pontuação em tempo real
- 🚀 Física de gravidade e impulso
- 🎨 Gráficos ASCII coloridos
- 🎵 Interface de menu interativa
- 💀 Detecção precisa de colisão
- 🔄 Geração procedural de obstáculos
- ⚡ Jogabilidade fluida e responsiva

## 🎮 Como Jogar

### Controles

- **ESPAÇO** - Faz o pássaro voar/pular para cima
- **ESC** - Sair do jogo e voltar ao menu

### Mecânica do Jogo

1. O pássaro cai constantemente devido à gravidade
2. Pressione ESPAÇO para dar um impulso para cima
3. Passe pelas aberturas nos canos sem colidir
4. Cada cano ultrapassado adiciona 1 ponto
5. O jogo termina se você:
   - Colidir com um cano
   - Cair no chão
   - Bater no teto

### Dicas para Jogar

- ⏰ **Timing é tudo** - Não pressione espaço muito cedo ou tarde
- 👀 **Olhe à frente** - Antecipe a posição dos próximos canos
- 🎯 **Toque suave** - Toques curtos na barra de espaço dão mais controle
- 🧘 **Mantenha a calma** - A paciência é fundamental para pontuações altas

## 🛠️ Requisitos

### Sistema Operacional
- Windows 7 ou superior (utiliza Windows API)

### Compilador
- MinGW-w64 (GCC para Windows)
- Visual Studio 2015 ou superior (MSVC)
- Dev-C++
- Code::Blocks com MinGW

### Bibliotecas Necessárias
- `windows.h` - Manipulação do console e controle de cursor
- `conio.h` - Entrada de teclado sem buffer
- `iostream` - Entrada/saída padrão
- `time.h` - Geração de números aleatórios
- `stdlib.h` - Funções utilitárias
- `string.h` - Manipulação de strings

## 📦 Instalação

### Opção 1: Compilação Rápida (Recomendado)

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/passaro-voador.git
cd passaro-voador

# Compile com g++
g++ main.cpp -o PassaroVoador.exe

# Execute o jogo
./PassaroVoador.exe
```

### Opção 2: Usando CMake

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/passaro-voador.git
cd passaro-voador

# Crie o diretório de build
mkdir build
cd build

# Configure e compile
cmake ..
cmake --build .

# Execute o jogo
./PassaroVoador.exe
```

### Opção 3: Visual Studio

1. Abra o Visual Studio
2. Selecione **Arquivo** → **Novo** → **Projeto**
3. Escolha **Aplicativo de Console C++**
4. Adicione o arquivo `main.cpp` ao projeto
5. Compile com **Ctrl+Shift+B**
6. Execute com **F5** ou **Ctrl+F5** (sem debug)

### Opção 4: Dev-C++

1. Abra o Dev-C++
2. Vá em **Arquivo** → **Novo** → **Projeto**
3. Escolha "Console Application" e linguagem C++
4. Adicione o código ao arquivo principal
5. Pressione **F9** para compilar e executar

## 📁 Estrutura do Projeto

```
passaro-voador/
│
├── main.cpp              # Código fonte principal
├── CMakeLists.txt        # Configuração CMake (opcional)
├── README.md             # Esta documentação
├── LICENSE               # Licença MIT
├── .gitignore            # Arquivos ignorados pelo Git
│
└── screenshots/          # Capturas de tela
    ├── menu.png
    ├── gameplay.png
    └── gameover.png
```

## 🎯 Estrutura do Código

### Constantes Globais

```cpp
LARGURA_TELA = 90          // Largura total da janela
ALTURA_TELA = 26           // Altura da janela
LARGURA_JANELA = 70        // Largura da área de jogo
LARGURA_MENU = 20          // Largura do painel lateral
TAMANHO_ABERTURA = 7       // Tamanho da abertura nos canos
DIFERENCA_CANO = 45        // Distância entre canos
```

### Principais Funções

#### Gerenciamento de Display
- `irPara(x, y)` - Posiciona o cursor em coordenadas específicas
- `configurarCursor(visivel, tamanho)` - Configura visibilidade do cursor
- `desenharBorda()` - Renderiza as bordas do jogo

#### Lógica do Pássaro
- `desenharPassaro()` - Desenha o sprite do pássaro
- `apagarPassaro()` - Limpa o pássaro da posição anterior
- `posicaoPassaro` - Coordenada Y atual do pássaro (gravidade aplicada)

#### Lógica dos Canos
- `gerarCano(indice)` - Gera posição aleatória para abertura
- `desenharCano(indice)` - Renderiza um cano na tela
- `apagarCano(indice)` - Remove cano da tela
- `posicaoCano[]` - Array com posições X dos canos

#### Mecânica do Jogo
- `colisao()` - Detecta colisão entre pássaro e canos
- `atualizarPontuacao()` - Atualiza display da pontuação
- `jogar()` - Loop principal do jogo
- `fimDeJogo()` - Tela de game over

## 🎨 Personalização

### Ajustar Dificuldade

**Velocidade do Jogo:**
```cpp
Sleep(100);  // Diminua para mais rápido, aumente para mais lento
```

**Tamanho da Abertura:**
```cpp
#define TAMANHO_ABERTURA 7  // Aumente para facilitar, diminua para dificultar
```

**Força do Pulo:**
```cpp
if(tecla==32){
    if( posicaoPassaro > 3 )
        posicaoPassaro-=3;  // Aumente para pulos mais altos
}
```

**Gravidade:**
```cpp
posicaoPassaro += 1;  // Aumente para cair mais rápido
```

### Modificar o Sprite do Pássaro

Edite o array `passaro[2][6]` para criar um visual diferente:

```cpp
char passaro[2][6] = { '/','-','-','o','\\',' ',
                       '|','_','_','_',' ','>' };
```

Exemplo alternativo:
```cpp
char passaro[2][6] = { ' ','<','(','o',')',' ',
                       ' ',' ','\\','|','/',' ' };
```

### Modificar os Canos

Altere o caractere usado para desenhar os canos em `desenharCano()`:

```cpp
cout<<"***";  // Substitua por "|||", "###", "█████", etc.
```

## 🐛 Problemas Conhecidos

- ⚠️ **Plataforma específica**: Funciona apenas no Windows
- 🖥️ **Terminal necessário**: Requer console do Windows nativo
- 🎨 **Codificação de caracteres**: Alguns terminais podem não exibir corretamente os caracteres ASCII estendidos
- 📱 **Não portável**: Não funciona em sistemas Unix/Linux/Mac sem modificações
- ⌨️ **Dependência de conio.h**: Biblioteca não padrão, específica do Windows

## 🔧 Solução de Problemas

### Erro: "conio.h: No such file or directory"

**Solução**: Use um compilador para Windows (MinGW, MSVC) que inclui esta biblioteca.

### Caracteres estranhos na tela

**Solução**: Configure o console para usar a página de código correta:

```cpp
// Adicione no início do main()
system("chcp 850");  // Ou chcp 437
```

### O pássaro não responde ao espaço

**Solução**: 
- Certifique-se de que a janela do console está em foco
- Verifique se não há outras aplicações capturando entrada de teclado
- Tente executar como administrador

### Jogo muito rápido ou muito lento

**Solução**: Ajuste o valor em `Sleep()` no loop principal:

```cpp
Sleep(100);  // Experimente valores entre 50-150
```

### Erro de compilação com '\xB1'

**Solução**: O código já usa `\xB1` (representação hexadecimal) ao invés de caracteres Unicode diretos. Se ainda houver problemas, substitua por outro caractere como `'#'` ou `'|'`.

## 🚀 Melhorias Futuras

### Recursos Planejados
- [ ] Sistema de high score com salvamento em arquivo
- [ ] Múltiplos níveis de dificuldade (Fácil, Médio, Difícil, Impossível)
- [ ] Efeitos sonoros (beeps do sistema)
- [ ] Skins alternativas para o pássaro
- [ ] Modo de prática sem game over
- [ ] Estatísticas de jogo (tentativas, melhor pontuação, tempo jogado)
- [ ] Conquistas/achievements
- [ ] Power-ups especiais
- [ ] Modo noturno (cores diferentes)

### Melhorias Técnicas
- [ ] Portabilidade para Linux/Mac usando ncurses
- [ ] Otimização do rendering (apenas redesenhar o que mudou)
- [ ] Implementar física mais realista
- [ ] Adicionar suporte a joystick/gamepad
- [ ] Criar versão gráfica com SDL ou SFML
- [ ] Multiplayer local (modo versus)

## 🎓 Aprendizado

Este projeto é excelente para aprender:

- 📚 **Lógica de programação** - Loops, condicionais, funções
- 🎮 **Desenvolvimento de jogos** - Game loop, física, colisão
- 🖥️ **Programação de console** - Manipulação de cursor, renderização
- 🔢 **Arrays e estruturas de dados** - Gerenciamento de múltiplos objetos
- ⏱️ **Timing e delays** - Controle de FPS e velocidade
- 🎨 **ASCII art** - Criação de gráficos com caracteres
- 🐛 **Debugging** - Resolução de problemas de lógica

## 📝 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

```
MIT License

Copyright (c) 2024 [Seu Nome]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

## 👤 Autor

**EDILSON SALVADOR RICCI**
- GitHub: GitHub: https://github.com/ESRicci26
- 📧 Email: esricci26@gmail.com
- 💼 LinkedIn: www.linkedin.com/in/edilson-salvador-ricci-82b771b7

## 🤝 Contribuindo

Contribuições são muito bem-vindas! Este é um projeto educacional e toda ajuda é apreciada.

### Como Contribuir

1. 🍴 Fork o projeto
2. 🔨 Crie uma branch para sua feature (`git checkout -b feature/MinhaFeature`)
3. ✅ Commit suas mudanças (`git commit -m 'Adiciona MinhaFeature'`)
4. 📤 Push para a branch (`git push origin feature/MinhaFeature`)
5. 🎉 Abra um Pull Request

### Diretrizes

- Mantenha o código legível e bem comentado
- Teste suas mudanças antes de enviar
- Atualize a documentação se necessário
- Siga o estilo de código existente
- Seja respeitoso nos comentários e discussões

## 🌟 Agradecimentos Especiais

- **Dong Nguyen** - Criador do Flappy Bird original
- **Comunidade C++** - Pela documentação e suporte
- **Stack Overflow** - Pelas inúmeras soluções de problemas
- **Você** - Por jogar e contribuir com este projeto!

## 📸 Screenshots

### Menu Principal
```
 -------------------------- 
 |    Passaro Voador     | 
 --------------------------
1. Iniciar Jogo
2. Instrucoes
3. Sair

Selecione uma opcao:
```

### Gameplay
```
±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
              ***         ±  PASSARO VOADOR
              ***         ±  --------------
              ***         ±  Pontuacao: 5
  /--o\                  ±  --------------
  |___ >                 ±  
              ***         ±  Controle
              ***         ±  --------
              ***         ±  Espaco = pular
±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
```

## 📚 Recursos Adicionais

### Tutoriais Relacionados

### Referências

## 📊 Estatísticas do Projeto

- **Linguagem**: C++
- **Linhas de código**: ~250
- **Funções**: 15+
- **Dificuldade**: ⭐⭐⭐⭐⭐ (Difícil como o original!)

---

⭐ **Se você gostou deste projeto, considere dar uma estrela no repositório!**

🎮 **Divirta-se jogando e boa sorte batendo seu recorde!**
