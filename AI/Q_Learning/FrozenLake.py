import gym
import numpy as np

# Load the environment
env = gym.make('FrozenLake8x8-v1')
Q = np.zeros([env.observation_space.n, env.action_space.n]) # -> no. of states and actions in env loaded

# Q-learning parameters
eta = .628
gma = .9
epis = 5000     # Episodes

rev_list = [] # rewards per episode calculate

# Q-Learning algorithm
for i in range(epis):
    # Reset env
    s = env.reset()
    rAll = 0
    d = False
    j = 0

    while j < 99:
        env.render()
        j += 1

        # Choose action from Q table
        a = np.argmax(Q[s,:] + np.random.randn(1, env.action_space.n) * (1./(i+1)))

        # Get new state & reward env
        s1, r, d, _ = env.step(a)

        # Update Q-table with new knowledge
        Q[s, a] = Q[s, a] + eta * (r + gma * np.max(Q[s1,:]) - Q[s,a])
        rAll += r
        s = s1
        if d:
            break

    rev_list.append(rAll)
    env.render()

print("Reward Sum on all episodes " + str(sum(rev_list)/epis))
print("Final Values Q-Table")
print(Q)