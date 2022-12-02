import random
import torch
import torchvision
import numpy as np

# Load model of choice
model = torchvision.models.resnet18()

# Generate random input for tracing
input = torch.rand(1, 3, 224, 224)

# Use jit.trace to translate the model
traced_module = torch.jit.trace(model, input)

# Save the model
traced_module.save('traced_resnet_model.pt')