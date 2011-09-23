import sys, os

"""
The original version of Scorekeeper

Just a text-only and extremely simple program that
I wrote in about an hour.
"""

players = {}

def init():
  """
  initialize the players dict by asking for a series of names
  """
  while True:
    name = raw_input("Please enter player name[blank if done]: ")
    if not name:
      break
    players[name] = 0
  if not players:
    sys.exit(0)


def printscore():
  """
  I'm amazed that this function works...
  Sort of iterate through the dict, printing the scores...
  """
  print("Current Score:")
  print("\t".join(players.keys()))
  scores = ""
  for value in players.values():
    scores += str(value)+"\t"
  print(scores)


def getscore():
  """
  Ask for an update for each player's score.
  """
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
  """
  loop back and forth between showing the scores and updating them
  """
  init()
  while True:
    printscore()
    getscore()


def snd(x):
  return x[-1]


def end_game():
  """
  just announce the winner, using deprecated os.system! eww!
  """
  (winner, score) = sorted(players.items(), key=snd, reverse=True)[0]
  os.system("figlet the winner is "+winner+"!")
  sys.exit(0)


if __name__=="__main__":
  main()
