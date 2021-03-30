<h1 align="center">concordo</h1>

<p align="center">
  <a href="#sobre">Sobre</a> –
  <a href="#como-rodar">Como rodar</a> –
  <a href="#funcionalidades-e-exemplos">Funcionalidades e Exemplos</a> –
  <a href="#autora">Autora</a>
</p>

## Sobre

O Concordo é um clone do discord desenvolvido em C++ para a disciplina de Linguagem de Programação I.

## Como rodar

Execute os seguintes comandos no seu terminal:

```bash
#compile o projeto
$ make
#você pode executar o projeto e digitar os comandos seguidos de enter
$ ./concordo
#ou pode alterar o arquivo script_comandos.txt com uma lista de comandos, um por linha, e redirecionar esse arquivo como entrada padrão
$ ./concordo < script_comandos.txt
#para limpar tudo
$ make clean
```

## Funcionalidades e Exemplos
Cada comando tem um nome seguido de parâmetros e devem ser digitados por linha. <br>
Abaixo seguem exemplos de cada comando do sistema.


### Criar usuário (*create-user*)
Cria um usuário no sistema, caso email e nome sejam diferentes de vazio e o email ainda não esteja registrado no sistema.

#### Exemplo
```bash
#comando para criar usuário
$ create-user example@email.com password name
#saída
Usuário criado com sucesso!
```

### Entrar no sistema (*login*)
Efetua login de usuário, caso esteja cadastrado no sistema e suas credenciais estejam corretas.

#### Exemplo
```bash
#comando para efetuar login
$ login example@email.com wrong_password
#saída
Senha ou usuário inválidos!
#comando para efetuar login
$ login example@email.com password
#saída
Logado como example@email.com
```
### Desconectar usuário do sistema (*disconnect*)
Efetua logout do usuário atualmente autenticado no sistema.

#### Exemplo
```bash
#comando para logout
$ disconnect
#saída
Desconectando usuário example@email.com
```
### Obs.: 
– Para executar com sucesso qualquer um dos comandos abaixo, é necessário estar autenticado no sistema –
 
### Criar servidor (*create-server*)
Cria servidor no sistema, caso nome seja diferente de vazio e ainda não esteja cadastrado. 

#### Exemplo
```bash
#comando para criar servidor
$ create-server kpop
#saída
Servidor criado com sucesso!
```

### Alterar descrição de servidor (*set-server-desc*)
Altera descrição de um servidor, que inicialmente é vazia. Dessa forma, o usuário pode alterá-la a qualquer momento, <br>
contanto que ele seja o dono do servidor.

#### Exemplo
```bash
#comando para alterar descrição de servidor
$ set-server-desc kpop1 "Esse servidor é tudo"
#saída
Servidor ‘kpop1’ não existe
#comando para alterar descrição de servidor
$ set-server-desc kpop "Esse servidor é tudo"
#saída
Descrição do servidor ‘kpop’ modificada!
```

### Alterar código convite de servidor (*set-server-invite-code*)
Altera código convite de um servidor que inicialmente é aberto. <br>
Caso o usuário (dono do servidor) queira torná-lo fechado, basta digitar o comando set-server-invite-code, <br> 
o nome do servidor e o código convite. Agora, caso o usuário queira deixar o servidor aberto novamente, <br>
basta passar nenhum código.

#### Exemplo
```bash
#comando para adicionar código convite ao servidor
$ set-server-invite-code kpop 1234
#saída
Código de convite do servidor ‘kpop’ modificado!
#comando para remover código convite de um servidor (basta não digitar nenhum código)
$ set-server-invite-code kpop
#saída
Código de convite do servidor ‘kpop’ removido!
```

### Listar servidores (*list-servers*)
Lista servidores registrados no sistema, mostrando seus nomes, descrição (caso exista) e se é aberto ou fechado.

#### Exemplo
```bash
#comando para listar servidores
$ list-servers
#saída
kpop: Esse servidor é tudo - fechado
```

### Entrar em um servidor (*enter-server*)
Adiciona e conecta usuário a um servidor. Caso usuário logado seja dono do servidor ou servidor seja aberto, 
não é necessário digitar código convite para entrar.

#### Exemplo
```bash
#comando para entrar em um servidor
$ enter-server kpop 1234
#saída
Entrou no servidor com sucesso
```

### Listar participantes de um servidor (*list-participants*)
Lista participantes do servidor no qual o usuário está conectado no momento.

#### Exemplo
```bash
#comando para listar participantes de um servidor
$ list-participants
#saída
Mariane
Julia
```

### Sair/desconectar de um servidor (*leave-server*)
Desconecta o usuário do servidor no qual está conectado no momento.

#### Exemplo
```bash
#comando para sair de um servidor
$ leave-server
#saída
Saindo do servidor ‘kpop’
```

### Remover um servidor (*remove-server*)
Remove servidor pelo nome, caso usuário logado seja seu dono.

#### Exemplo
```bash
#comando para remover servidor
$ remove-server kpop
#saída
Servidor ‘kpop’ removido
```

### Sair do sistema (*quit*)
Encerra a aplicação. 

#### Exemplo
```bash
#comando para encerrar/sair do programa
$ quit
#saída
Saindo do Concordo...
```

## Autora
Feito por [Mariane Felix Fernandes](https://www.linkedin.com/in/mariane-felix-642350171/).
