import time
import turtle
import tkinter
from tkinter import ttk
# Initalization Variables

px = 40 # pixel size of square
sz = 10 # board size
y = -200 # y base
w = 4 # dist from x = 0 line in our coordinates
psz = 5 # pen size
ship_set = [2, 3, 3, 4, 5] # ship set


win_len = 0
for i in ship_set: 
    win_len += i
def winner(hit_set):
    if len(hit_set) == win_len:
        return True
    return False
############################ DRAWING SECTION ####################################################################
#########################################



s = turtle.Screen()
t = turtle.Turtle()
t.hideturtle()
t.speed(0)

def circle(x, y, color):
    global px
    t.pensize(w)
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.fillcolor(color)
    t.begin_fill()
    t.circle(px/2-1)
    t.end_fill()

def shipdraw(start_coord, end_coord, length):
    #startcoord should have lower left turtle coordinate corner of the square, and endcoord should have upper right turtle coordinate corner of the square.
    # Also start_coord is the one closer to [1,1].
    t.pensize()
    t.penup()
    t.pencolor("orange")
    t.fillcolor('gray')
    t.goto(start_coord[0], start_coord[1])
    t.pd()
    t.begin_fill()
    t.goto(start_coord[0], end_coord[1])
    t.goto(end_coord[0], end_coord[1])
    t.goto(end_coord[0], start_coord[1])
    t.goto(start_coord[0], start_coord[1])
    t.end_fill()


def showyourboard(ships, hit_shots, missed_shots):
    # Makes main square
    t.pu()
    startx = - px * (sz + w)
    starty = y
    t.pencolor("black")
    t.pensize(psz)
    t.fillcolor("teal")
    t.goto(startx, y)
    t.pd()

    # Creates Square
    t.begin_fill()
    for i in range(4):
        t.forward(px * sz)
        t.left(90)
    t.end_fill()

    # Creates Horz Grid Lines
    for i in range(sz + 1):
        t.goto((startx, starty + px*i))
        t.pd()
        t.goto((startx + sz * px, starty + px*i))
        t.pu()

    # Creates Vert Grid Lines
    for i in range(sz + 1):
        t.goto((startx + px * i, starty))
        t.pd()
        t.goto((startx + px * i, starty + sz * px))
        t.pu()

    for ship in ships:
        length_of_ship = abs(ship[0][0]-ship[1][0])+abs(ship[0][1]-ship[1][1])
        shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), y + px*(ship[0][1] - 1)], 
             [-px*(w + sz) + px * ship[1][0], y + px*(ship[1][1])], length_of_ship)
    for hit in hit_shots:
        circle( -px*(w+sz)   +    px * (hit[0]- 1)+px/2, y + px*(hit[1] - 1), 'red')

    for miss in missed_shots:
        circle( -px*(w+sz)   +    px * (miss[0]- 1)+px/2, y + px*(miss[1] - 1), 'white')

def showoppboard(hit_shots, missed_shots):
    # Makes main square
    t.pu()
    startx = px * w
    starty = y
    t.pencolor("black")
    t.pensize(psz)
    t.fillcolor("teal")
    t.goto(startx, y)
    t.pd()

    # Creates Square
    t.begin_fill()
    for i in range(4):
        t.forward(px * sz)
        t.left(90)
    t.end_fill()

    # Creates Horz Grid Lines
    for i in range(sz + 1):
        t.goto((startx, starty + px*i))
        t.pd()
        t.goto((startx + sz * px, starty + px*i))
        t.pu()

    # Creates Vert Grid Lines
    for i in range(sz + 1):
        t.goto((startx + px * i, starty))
        t.pd()
        t.goto((startx + px * i, starty + sz * px))
        t.pu()

    for hit in hit_shots:
        circle( px*w   +    px * (hit[0]- 1)+px/2, y + px*(hit[1] - 1), 'red')

    for miss in missed_shots:
        circle( px*w   +    px * (miss[0]- 1)+px/2, y + px*(miss[1] - 1), 'white')

############################ CODING SECTION ##############################################################################################################

# Define global variables that will be used during ship selection
count = 0
ship = []

# Function to deal with clicks to choose two endpoints of a ship:
def click_for_ship_selection(clickx, clicky):
    global count, ship
    ycoord = int((clicky - y) // px + 1)
    xcoord = int((clickx + px * (sz + w)) // px + 1)
    if 1 <= xcoord <= sz and 1 <= ycoord <= sz:
        ship.append([xcoord, ycoord])
        count += 1

    if count >= 2:
        s.onscreenclick(None)  # Disable the event handler to stop further clicks

allshots_foraplayer = []
spotclicked=[]

def click_for_shooting(clickx, clicky):
    global spotclicked, count
    ycoord= int((clicky - y)//px + 1)
    #subtract xcoordinate of left side of board from clickx on next line
    xcoord = int((clickx    -     px*w   ) // px + 1)
    if 1 <= xcoord <= sz and 1 <= ycoord <= sz and [xcoord, ycoord] not in allshots_foraplayer:
        spotclicked = [xcoord, ycoord]
        count +=1

    if count == 1:
        s.onscreenclick(None)


def checkshipplace(shiplen, co1, co2, usedships):
    if co1[0] < 1 or co1[0] > sz:
        return False
    if co1[1] < 1 or co1[1] > sz:
        return False
    if co2[0] < 1 or co2[0] > sz:
        return False
    if co2[1] < 1 or co2[1] > sz:
        return False
    if co1[0] == co2[0]:  # vertical
        if shiplen-1 == abs(co1[1]-co2[1]):  # Checks it has right length
            for i in range(co1[1], co2[1]+1):  # Now checks each part of the ship is in an unused coordinate
                if [co1[0], i] in usedships:
                    return False
            return True
        else:
            return False
    elif co1[1] == co2[1]:  # horizontal
        if shiplen-1 == abs(co1[0]-co2[0]):  # Checks it has right length
            for i in range(co1[0], co2[0]+1):  # Now checks each part of the ship is in an unused coordinatek
                if [i, co1[1]] in usedships:
                    return False
            return True
        else:
            return False
    else:  # diagonal ship
        return False

def getnames():
    name1, name2 = turtle.textinput("Player names", "Please enter your names, separated by a comma followed by a space (like 'Billy Bob, Goofy Garud'): ").split(", ")
    return name1, name2


############### MAIN CODE #######################

# Begin battleship, opening credits
names = getnames()
p1 = names[0]
p2 = names[1]
tkinter.messagebox.showinfo("Welcome message", """
Welcome to battleship, my fellow pirates """ + str(p1) + ' and ' + str(p2) + '.' + """ Here are the rules of the game. 

Each player will be given a 7x7 board, and will place four ships with length 2, 3, 4, and 5. 
Your goal is to sink all of your opponent's ships before they sink yours.
On a turn, a player will be allowed to guess a coordinate on the opponent's board. 
    If the coordinate is a hit, they will get a red marker on that portion of the board. 
    If the coordinate is a miss, they will get a white marker. 
The game will end when all of one player's ships are sunk. """)

# P1 places ships

p1_used_ships = []
p1ships = []
showyourboard([], [], [])
showoppboard([], [])
while (not tkinter.messagebox.askyesno(p2 + "'s Ship Placement", p2 + """, place your ships! \nYou will now click on 2 boxes that are the endpoints of your ship. Has your opponent looked away?""")):
    """This is an infinite while loop to do nothing, just for conformation."""
for i in [2,3,3,4,5]:  ###Places ship of length i
    count = 0
    ship = []
    tkinter.messagebox.showinfo("Length of selected ship", "The length of your next ship to place is "+str(i)+"!")
    s.onscreenclick(click_for_ship_selection) #Selects the click handler to deal with sleecting two squares for a shipp
    while count < 2:
        s.update()  # Ensure the screen updates to capture the clicks
    s.onscreenclick(None)  # Disable the event handler after ship is placed
    while not checkshipplace(i, ship[0], ship[1], p1_used_ships):
        tkinter.messagebox.showerror("Invalid Ship Selection", "The ship you have entered is invalid.\nPlease try again.")
        count = 0
        ship = []
        s.onscreenclick(click_for_ship_selection)
        while count < 2:
            s.update()  # Ensure the screen updates to capture the clicks
        s.onscreenclick(None)  # Disable the event handler after ship is placed
    ship = sorted(ship, key=lambda x: x[1])
    ship = sorted(ship, key=lambda x: x[0]) # This is to sort the ship in 'increasing' order like [[1,3],[2,3]] rather than the other way around. The key=lambda x: x[n] is used to sort by nth element


    for i in range(ship[0][0], ship[1][0]+1):
        for j in range(ship[0][1], ship[1][1]+1):
            p1_used_ships.append([i, j])
    p1ships.append(ship)


    #Now we draw the board for now
    shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), y + px*(ship[0][1] - 1)], 
             [-px*(w + sz) + px * ship[1][0]      , y + px*(ship[1][1])], i)

time.sleep(4)

s.clearscreen()


#P2 will now play their board

p2_used_ships = []
p2ships = []
showyourboard([], [], [])
showoppboard([], [])
while (not tkinter.messagebox.askyesno(p2 + "'s Ship Placement", p2 + """, place your ships! \nYou will now click on 2 boxes that are the endpoints of your ship. Has your opponent looked away?""")):
    """This is an infinite while loop to do nothing, just for conformation."""
for i in ship_set:  ###Places ship of length i
    tkinter.messagebox.showinfo("Length of selected ship", "The length of your next ship to place is "+str(i)+"!")
    count = 0
    ship = []
    s.onscreenclick(click_for_ship_selection) #Selects the click handler to deal with selecting two squares for a ship
    while count < 2:
        s.update()  # Ensure the screen updates to capture the clicks
    s.onscreenclick(None)  # Disable the event handler after ship is placed
    print(ship)

    while not checkshipplace(i, ship[0], ship[1], p2_used_ships):
        tkinter.messagebox.showerror("Invalid Ship Selection", "The ship you have entered is invalid.\nPlease try again.")
        count = 0
        ship = []
        s.onscreenclick(click_for_ship_selection)
        while count < 2:
            s.update()  # Ensure the screen updates to capture the clicks
        s.onscreenclick(None)  # Disable the event handler after ship is placed
        print(ship)

    ship = sorted(ship, key=lambda x: x[1])
    ship = sorted(ship, key=lambda x: x[0]) # This is to sort the ship in 'increasing' order like [[1,3],[2,3]] rather than the other way around. The key=lambda x: x[n] is used to sort by nth element


    for i in range(ship[0][0], ship[1][0]+1):
        for j in range(ship[0][1], ship[1][1]+1):
            p2_used_ships.append([i, j])
    p2ships.append(ship)


    #Now we draw the board for now
    shipdraw([-px*(w + sz) + px * (ship[0][0] - 1), y + px*(ship[0][1] - 1)], 
         [-px*(w + sz) + px * ship[1][0], y + px*(ship[1][1])], i)
time.sleep(4)
s.clearscreen()


#Now both players have placed their ships, we can start the game

p1hits = []
p1miss = []
p1allshots = []
p2hits = []
p2miss = []
p2allshots = []
outcome = ""


while not (winner(p1hits) and winner(p2hits)):
    tkinter.messagebox.askyesno("Player 1's turn", p1 + ", please click the coordinate you would like to attack on your opponent's board once the board loads.")
    showyourboard(p1ships, p2hits, p2miss)
    showoppboard(p1hits, p1miss)

    count =0
    spotclicked = []
    allshots_foraplayer = p1allshots
    s.onscreenclick(click_for_shooting)
    while count < 1:
        s.update()
    s.onscreenclick(None)
    if spotclicked in p2_used_ships:
        #Add xcoordinate of left side of board on next line
        circle( px*w   +    px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
        p1hits.append(spotclicked)
        outcome = "hit"
    else:
        #Add xcoordinate of left side of board on next line
        circle( px*w     +   px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
        p1miss.append(spotclicked)
        outcome = "missed"
    p1allshots.append(spotclicked)

    time.sleep(3)
    s.clearscreen()
    r = tkinter.messagebox.showinfo("Notification", p1 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p2 + "'s board.")

    if len(p1hits) < len(p1_used_ships):
        r = tkinter.messagebox.showinfo("Player 2's turn", p2 + ", please click the coordinate you would like to attack on your opponents board once the board loads.")
        showyourboard(p2ships, p1hits, p1miss)
        showoppboard(p2hits, p2miss)
        count = 0
        spotclicked = []
        allshots_foraplayer = p2allshots
        s.onscreenclick(click_for_shooting)
        while count < 1:
            s.update()
        s.onscreenclick(None)
        if spotclicked in p1_used_ships:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
            p2hits.append(spotclicked)
            outcome = "hit"
        else:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
            p2miss.append(spotclicked)
            outcome = "missed"
        p2allshots.append(spotclicked)
        time.sleep(3)
        s.clearscreen()
        r = tkinter.messagebox.showinfo("Notification", p2 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p1 + "'s board.")
    # for p1
    tkinter.messagebox.showinfo("Player 1's turn", p1 + ", please click the coordinate you would like to attack on your opponent's board once the board loads.")
    showyourboard(p1ships, p2hits, p2miss)
    showoppboard(p1hits, p1miss)

    count =0
    spotclicked = []
    allshots_foraplayer = p1allshots
    spotclicked = s.onscreenclick(click_for_shooting)
    s.update()
    s.onscreenclick(None)
    if spotclicked in p2_used_ships:
        #Add xcoordinate of left side of board on next line
        circle( px*w   +    px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
        p1hits.append(spotclicked)
        outcome = "hit"
    else:
        #Add xcoordinate of left side of board on next line
        circle( px*w     +   px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
        p1miss.append(spotclicked)
        outcome = "missed"
    p1allshots.append(spotclicked)

    time.sleep(3)
    s.clearscreen()


    tkinter.messagebox.showinfo("Notification", p1 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p2 + "'s board.")

    if len(p1hits) < len(p1_used_ships):
        tkinter.messagebox.askyesno("Player 1's turn", p1 + ", please click the coordinate you would like to attack on your opponent's board once the board loads.")
        showyourboard(p2ships, p1hits, p1miss)
        showoppboard(p2hits, p2miss)
        count =0
        spotclicked = []
        allshots_foraplayer = p2allshots
        spotclicked = s.onscreenclick(click_for_shooting)
        while count < 1:
            s.update()
        s.onscreenclick(None)
        if spotclicked in p1_used_ships:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
            p2hits.append(spotclicked)
            outcome = "hit"
        else:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
            p2miss.append(spotclicked)
            outcome = "missed"
        p2allshots.append(spotclicked)
        time.sleep(3)
        s.clearscreen()
        tkinter.messagebox.showinfo("Notification", p2 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p1 + "'s board.")
    tkinter.messagebox.showinfo("Player 2's turn", p2 + ", please click the coordinate you would like to attack on your opponent's board once the board loads.")
    showyourboard(p2ships, p1hits, p1miss)
    showoppboard(p2hits, p2miss)

    count =0
    spotclicked = []
    allshots_foraplayer = p1allshots
    s.onscreenclick(click_for_shooting)
    s.update()
    s.onscreenclick(None)
    if spotclicked in p1_used_ships:
        #Add xcoordinate of left side of board on next line
        circle( px*w   +    px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
        p1hits.append(spotclicked)
        outcome = "hit"
    else:
        #Add xcoordinate of left side of board on next line
        circle( px*w     +   px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
        p1miss.append(spotclicked)
        outcome = "missed"
    p1allshots.append(spotclicked)

    time.sleep(3)
    s.clearscreen()
    tkinter.messagebox.showinfo("Notification", p1 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p2 + "'s board.")
    if len(p2hits) < len(p2_used_ships):
        tkinter.messagebox.askyesno("Player 2's turn", p2 + ", please click the coordinate you would like to attack on your opponent's board once the board loads.")
        showyourboard(p2ships, p1hits, p1miss)
        showoppboard(p2hits, p2miss)
        count =0
        spotclicked = []
        allshots_foraplayer = p2allshots
        spotclicked = s.onscreenclick(click_for_shooting)
        while count < 1:
            s.update()
        s.onscreenclick(None)
        if spotclicked in p1_used_ships:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'red')
            p2hits.append(spotclicked)
            outcome = "hit"
        else:
            circle(px * (spotclicked[0]- 1)+px/2, y + px*(spotclicked[1] - 1), 'white')
            p2miss.append(spotclicked)
            outcome = "missed"
        p2allshots.append(spotclicked)
        time.sleep(3)
        s.clearscreen()
        tkinter.messagebox.showinfo("Notification", p2 + " has " + outcome + " a shot at " + str(spotclicked) + " on " + p1 + "'s board.")
#what happens when game is over
if (winner(p1hits)):
    tkinter.messagebox.showinfo("Winner", p1 + " is the WINNER! All pirates, bow down.")
if (winner(p2hits)):
    tkinter.messagebox.showinfo("Winner", p2 + " is the WINNER! All pirates, bow down.")