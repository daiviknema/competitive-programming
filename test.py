import numpy as np
import sys

from lstm import LstmParam, LstmNetwork

class ToyLossLayer:
    """
    Computes square loss with first element of hidden layer array.
    """
    @classmethod
    def loss(self, pred, label):
        return (pred[0] - label) ** 2

    @classmethod
    def bottom_diff(self, pred, label):
        diff = np.zeros_like(pred)
        diff[0] = 2 * (pred[0] - label)
        return diff

def example_0():
    # learns to repeat simple sequence from random inputs
    np.random.seed(0)

    # parameters for input data dimension and lstm cell count 
    mem_cell_ct = 100
    x_dim = 50
    lstm_param = LstmParam(mem_cell_ct, x_dim) 
    lstm_net = LstmNetwork(lstm_param)
    y_list = [-0.5,0.2,0.1, -0.5]
    input_val_arr = [np.random.random(x_dim) for _ in y_list]

    for cur_iter in range(100):
        print("cur iter: " + str(cur_iter))
        for ind in range(len(y_list)):
            lstm_net.x_list_add(input_val_arr[ind])
            print("y_pred[" + str(ind) + "] : " + str(lstm_net.lstm_node_list[ind].state.h[0]))

        loss = lstm_net.y_list_is(y_list, ToyLossLayer)
        print("loss: " + str(loss))
        lstm_param.apply_diff(lr=0.1)
        lstm_net.x_list_clear()

def example_1():
    # learns to repeat simple sequence from random inputs
    np.random.seed(0)

    # parameters for input data dimension and lstm cell count 
    mem_cell_ct = 100
    x_dim = 48
    lstm_param = LstmParam(mem_cell_ct, x_dim) 
    lstm_net = LstmNetwork(lstm_param)
    y_list = []
    input_val_arr = []
    with open('LSTM_Data_train.csv') as fp:
        line = fp.readline()
        while True:
            line = fp.readline()
            if line == "": break
            x = np.array(map(float, line.split(',')[1:-1]))
            #print map(float, line.split(',')[1:-1])
            #print float(line.split(',')[-1])
            #raw_input()
            y = float(line.split(',')[-1])
            y_list.append(y)
            input_val_arr.append(x)

    for cur_iter in range(2000):
        #print("cur iter: " + str(cur_iter))
        for ind in range(len(y_list)-48):
            lstm_net.x_list_add(input_val_arr[ind])
            #print("y_pred[" + str(ind) + "] : " + str(lstm_net.lstm_node_list[ind].state.h[0]))
            #print >> sys.stderr, "y_pred[" + str(ind) + "] : " + str(lstm_net.lstm_node_list[ind].state.h[0])

        loss = lstm_net.y_list_is(y_list[:-48], ToyLossLayer)
        print cur_iter, loss,
        print >> sys.stderr, "Training Loss: "+str(loss)
        #print("loss: " + str(loss))
        #raw_input()
        lstm_param.apply_diff(lr=0.001)
        lstm_net.x_list_clear()
        for ind in range(len(y_list)-48, len(y_list)):
            lstm_net.x_list_add(input_val_arr[ind])
        loss = lstm_net.y_list_is(y_list[-48:], ToyLossLayer)
        print >> sys.stderr, "Test Loss: "+str(loss)
        lstm_net.x_list_clear()

    for ind in range(len(y_list)-48, len(y_list)):
        lstm_net.x_list_add(input_val_arr[ind])
        print >> sys.stderr, 'input: '+str(input_val_arr[ind])
        print >> sys.stderr, "y_pred[" + str(ind-len(y_list)+49) + "] : " + str(lstm_net.lstm_node_list[ind-len(y_list)+48].state.h[0])
    loss = lstm_net.y_list_is(y_list[-48:], ToyLossLayer)
    print >> sys.stderr, "Test Loss: "+str(loss)
    lstm_net.x_list_clear()


if __name__ == "__main__":
    example_1()
