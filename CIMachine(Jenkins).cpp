// Jenkins file
pipeline{
    agent any
    stages('Build'){
        steps{
            sh 'echo "Building..."'
            sh 'chmod +x scripts/Linux-Build.sh'
            sh 'scripts/linux-Build.sh'
            archiveArtifacts artifacts: 'bin/Debug/*', fingerprint: true
        }
    }
    stage('Test'){
        steps{
            sh 'echo "Running..."'
            sh 'chmod +x scripts/Linux-Run.sh'
            sh 'scripts/Linux-Run.sh'
        }
    }
}