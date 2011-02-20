import sys, os

players = {}

def init():
  while True:
    name = raw_input("Please enter player name[blank if done]: ")
    if not name:
      break
    players[name] = 0
  if not players:
    sys.exit(0)


def printscore():
  print("Current Score:")
  print("\t".join(players.keys()))
  scores = ""
  for value in players.values():
    scores += str(value)+"\t"
  print(scores)


def getscore():
  for player in players:
    while True:
      try:
        val = int(raw_input("Score for "+player+"['-1' to exit]: "))
        if val == -1:
          end_game()
        break
      except ValueError:
        print("Oops, invalid input!")
    players[player] += val


def main():
  init()
  while True:
    printscore()
    getscore()


def snd(x):
  return x[-1]


def end_game():
  (winner, score) = sorted(players.items(), key=snd, reverse=True)[0]
  os.system("figlet the winner is "+winner+"!")
  sys.exit(0)


if __name__=="__main__":
  main()
