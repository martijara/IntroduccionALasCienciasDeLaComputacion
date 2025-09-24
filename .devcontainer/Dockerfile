# Use a Miniconda base image with mamba for faster installs
FROM mambaforge/mambaforge:latest

# Install system utilities
RUN apt-get update && apt-get install -y git wget build-essential && rm -rf /var/lib/apt/lists/*

# Install xeus-cling C++ kernel and JupyterLab
RUN mamba install -c conda-forge xeus-cling jupyterlab -y

# Expose the Jupyter port so Codespaces can forward it
EXPOSE 8888

# Start Jupyter Lab by default to test in container (optional)
CMD ["jupyter", "lab", "--ip=0.0.0.0", "--port=8888", "--no-browser", "--allow-root"]